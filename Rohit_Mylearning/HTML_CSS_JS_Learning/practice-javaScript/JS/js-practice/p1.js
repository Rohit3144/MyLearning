// Write a function which returns a new function that always returns "Hello World"
var fn = function () {
    return function () {
        return "Hello World"
    }
}
fn()