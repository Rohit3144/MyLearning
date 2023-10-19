const express = require("express");
const path = require("path");
const fs = require("fs");
const app = express();
const port = 3000;

// Express specific stuff
app.use('/static', express.static('static'))        // for serving static files
// To extract data from website
app.use(express.urlencoded())       // Without this we can't be seen

// Pug specific stuff
app.set('view engine', 'pug')       // set the template engine as pug
app.set('views', path.join(__dirname, 'views'))     // set the views directory

// Endpoints
app.get('/', (req, res) => {
    const con = 'This is the best content on the internet by far so use it wisely'
    const params = { 'title': 'PubG is the best game on the internet', 'content': con }
    res.status(200).render('index.pug', params)
});

app.post('/', (req, res) => {
    console.log(req.body);
    name = req.body.name
    age = req.body.age
    gender = req.body.gender
    address = req.body.address
    more = req.body.more

    let outputToWrite = `the name of the client is ${name}, ${age} years old, ${gender}, residing at ${address}. More about him/her: ${more}`
    fs.writeFileSync('output.txt', outputToWrite)
    const params = { 'message': 'your form has been submitted successfully' }
    res.status(200).render('index.pug', params)
});

// Start the server
app.listen(port, () => {
    console.log(`The application started successfully on port ${port}`);
});
