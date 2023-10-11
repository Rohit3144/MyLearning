const fs = require('fs');
let text = fs.readFileSync('del.txt', 'utf-8');
// console.log(text);
text = text.replace('sooner or later', 'now');
console.log(text);

console.log('Creating a new file...');
fs.writeFileSync('newdel.txt', text);
text = fs.readFileSync('newdel.txt', 'utf-8');
console.log(text);