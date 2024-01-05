// Write a function which returns a new function that always returns "Hello World"

// var createHelloWorld = function() {
//     return function() {
//         return 'Hello World...'
//     }
// }
// // console.log(createHelloWorld)
// var f = createHelloWorld()
// console.log(f())

// // Count++
// var c = function(n) {
//     return function() {
//         return n++
//     }
// }
// const counter = c(10)
// console.log(counter())
// console.log(counter())

// counter()
// counter()
// counter()

// // Write a function createCounter. It should accept an initial integer init. It should return an object with three functions.
// // The three functions are:
// // increment() increases the current value by 1 and then returns it.
// // decrement() reduces the current value by 1 and then returns it.
// // reset() sets the current value to init and then returns it.

// var createCounter = function(init) {
//     let count = init
//     return {
//         increment: function() {
//             count++
//             return count
//     },
//     decrement: function() {
//         count--
//         return count;
//     },
//     reset: function() {
//         count = init
//         return count
//     }
//     }
// };
// const counter = createCounter(5)
// counter.increment(); // 6
// counter.reset(); // 5
// counter.decrement(); // 4


// Write a function expect that helps developers test their code. It should take in any value val and return an object with the following two functions.
// toBe(val) accepts another value and returns true if the two values === each other. If they are not equal, it should throw an error "Not Equal".
// notToBe(val) accepts another value and returns true if the two values !== each other. If they are equal, it should throw an error "Equal".


var expect = function(val) {
    return {
        toBe: function(val1) {
            console.log('This is to be')
            if(val !== val1) throw new Error('Not Equal')
            else return true;
        },
        notToBe: (val1) => {
            console.log('This is not to be')
            if(val === val1) {
                throw new Error('Equal')
            }
            else {
                return true;
            }

        }
    }
};

try {
    expect(5).toBe(5); // true
} catch(e) {
    console.log("Received Error");
}

try {
    expect(5).notToBe(5); // throws "Equal"
} catch(e) {
    console.log("Received Error");
}
