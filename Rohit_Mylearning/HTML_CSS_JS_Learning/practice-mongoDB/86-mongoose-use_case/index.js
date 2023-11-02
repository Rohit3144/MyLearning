// getting-started.js
const mongoose = require('mongoose');

mongoose.connect('mongodb://127.0.0.1:27017/test', {useNewUrlParser: true, useUnifiedTopology: true});

var db = mongoose.connection;
db.on('error', console.error.bind(console, 'connection error: '));

// db.once('open', function() {
//   // We are connceted
//   console.log('We are connceted to mongoose');
// });

var kittySchema = new mongoose.Schema({
  name: String
});

kittySchema.methods.speak = function speak() {
  var greeting = 'My name is ' + this.name
  console.log(greeting)
  // console.log('This is console log in speak function') 
}

var kitten = mongoose.model('kitten', kittySchema);

var harrykitty = new kitten({name: 'harrykitty'});
var harrykitty2 = new kitten({name: 'harrykitty2'});
// console.log(harrykitty.name);
// harrykitty.speak();

harrykitty.save();
// harrykitty.speak();
harrykitty2.save();
// harrykitty2.speak();

// To see whole database use this
// const kittens = kitten.find();
// console.log(kittens);

// To filter out a particular query 
// whichever name/object you want just give that name/object to find
kitten.find({name: 'harrykitty'}).then((kittenss) => {
  console.log(kittenss)
});





// getting-started.js
// const mongoose = require('mongoose');

// main().catch(err => console.log(err));

// async function main() {
//   await mongoose.connect('mongodb://127.0.0.1:27017/Prashant');

//   // use `await mongoose.connect('mongodb://user:password@127.0.0.1:27017/test');` if your database has auth enabled
// }

// var db = mongoose.connection;
// db.on('error', console.error.bind(console, 'connection error:'));
// db.once('open', function() {
//     // We are connected!
//     console.log("Hurray !!! we are connected to mongodb :)");
// });

// const kittySchema = new mongoose.Schema({
//   name: String
// });

// // NOTE: methods must be added to the schema before compiling it with mongoose.model()
// kittySchema.methods.speak = function speak() {
//   const greeting = this.name
//     ? 'Meow name is ' + this.name
//     : 'I don\'t have a name';
//   console.log(greeting);
// };

// const Kitten = mongoose.model('Kitten', kittySchema);

// const fluffy = new Kitten({ name: 'fluffy' });
// fluffy.speak(); // "Meow name is fluffy"

// fluffy.save();
// fluffy.speak();

// const kittens = Kitten.find();
// console.log(kittens);
