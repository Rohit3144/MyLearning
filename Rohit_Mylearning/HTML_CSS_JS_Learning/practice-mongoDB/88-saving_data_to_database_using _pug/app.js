const express = require("express");
const path = require("path");
// const fs = require("fs");
const app = express();
const bodyparser = require('body-parser');
const port = 3000;
var mongoose=require("mongoose");
// mongoose.connect('mongodb://localhost/contactDance', {useNewParser: true})
mongoose.connect('mongodb://localhost/contactDance')

// Define mongoose schema
var contactSchema = new mongoose.Schema({
    name: String,
    phone: String,
    email: String,
    address: String,
    description: String
  });

  var dataContact = mongoose.model('contact', contactSchema);

// Express specific stuff
app.use('/static', express.static('static'))        // for serving static files
// To extract data from website
app.use(express.urlencoded())       // Without this we can't be seen

// Pug specific stuff
app.set('view engine', 'pug')       // set the template engine as pug
app.set('views', path.join(__dirname, 'views'))     // set the views directory

// Endpoints
app.get('/', (req, res) => {

    const params = { }
    res.status(200).render('home.pug', params)
});

// Endpoints
app.get('/contact', (req, res) => {

    const params = { }
    res.status(200).render('contact.pug', params)
});

app.post('/contact',(req,res)=>{
    var myData = new dataContact(req.body);
    myData.save().then(()=>{
        res.send("Item saved successfully");
    }).catch(()=>{
        res.status(400).send("Item is not saved to the database");
    });
    })

// Start the server
app.listen(port, () => {
    console.log(`The application started successfully on port ${port}`);
});
