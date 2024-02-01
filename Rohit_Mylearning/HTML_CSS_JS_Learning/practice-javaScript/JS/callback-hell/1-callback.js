// Basic callback function

function calculate(n1, n2, cb) {
    return cb(n1, n2)
}

function sum(n1, n2) {
    return n1+n2
}
// function product(n1, n2) {
//     return n1*n2
// }

console.log(calculate(10, 20, sum))

// 1 and 2 are given in place of n1 and n2
console.log(calculate(1, 2, function() { 
    return (10+200) 
}));
// calculate(10, 2/0, product);



// ******************* This is ChatGPT code of callback function ****************************************

// // Simple function that takes a callback as an argument
// function doSomethingAsync(callback) {
//     console.log("Doing something asynchronously...");
    
//     // Simulating an asynchronous operation (e.g., fetching data from a server)
//     setTimeout(function() {
//         console.log("Async operation complete!");
//         // Execute the callback function
//         callback();
//     }, 2000); // Simulating a delay of 2 seconds
// }

// // Callback function to be passed to doSomethingAsync
// function callbackFunction() {
//     console.log("Callback function executed!");
// }

// // Call the function with the callback
// doSomethingAsync(callbackFunction);
