// getting-started.js
const mongoose = require('mongoose');

mongoose.connect('mongodb://127.0.0.1:27017/test');

var db = mongoose.connection;
db.on('error', console.error.bind(console, 'connection error: '));
db.once('open', function() {
  // We are connceted
  console.log('We are connceted to mongoose');
});