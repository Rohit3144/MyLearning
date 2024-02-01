function sum(c) {
    a = 10;
    console.log('This is sum function', a)
    // c(a)
}

function display(a) {
    c = 20;
    console.log('This is display function', c)
    a(c)
}

// sum(display)
display(sum)
// display(alert);  // This is throwing an error


// OR another way to do callback function
function x(y) {
    console.log('This is xxx function')
    y()
}
x(function () {console.log('This is yyy function')})
