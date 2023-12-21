// // Function currying with Bind() method
// let multiply = function(x, y) {
//     console.log(x*y)
// }
// let multi = multiply.bind(this, 3)
// let multiii = multiply.bind(this)
// multi(5)
// multiii(10, 2)

// Function currying with the help of Closure
// closure - function within a function or returning a function is called closure
let mul = function(x) {
    return function(y) {
        console.log(x*y)
    }
}
let mulll = mul(2)
mulll(20)