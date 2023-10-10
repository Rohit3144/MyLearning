console.log("hi.....This is function js file")

function greet(name, greetText = "Greetings from JavaScript") {
    console.log(greetText + " " + name);
    console.log(name + " is a good boy");
}

function sum(a, b, c) {
    let d = a + b + c;
    return d;
    // This line will never execute (Unreachable code)
    // console.log("Function is returned");
}

let name = 'Rahul';
let name1 = 'Rohit';
let name2 = 'RRR';

let greetText = 'Good morning'

greet(name, greetText);
greet(name1, greetText);
greet(name2);


// let name = 'Rahul';
// let name1 = 'Rohit';
// let name2 = 'RRR';

let returnVal = sum(1, 2, 3);
console.log(returnVal)

// console.log(name + " is a good boy");
// console.log(name1 + " is a good boy");
// console.log(name2 + " is a good boy");
