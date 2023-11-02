const express = require("express");
const path = require("path");
// const fs = require("fs");
const app = express();
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

  var contact = mongoose.model('contact', contactSchema);

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

// Start the server
app.listen(port, () => {
    console.log(`The application started successfully on port ${port}`);
});
