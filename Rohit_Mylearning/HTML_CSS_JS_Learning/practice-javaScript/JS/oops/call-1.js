// call is used when you want to control the scope that will be used in the function called. You might want the 'this' keyword to be something else than the scope you assigned the function to, in those cases you can use call or apply to call the function with your own scope.

// F.ex, it also allows you to call utility methods outside the scope, like when using "private" functions:

var obj = function() {
    var privateFn = function() {
        console.log(this.id);
        console.log(this.ic);
    }
    return {
        id: 123, ic: 456,
        publicFn: function() {
            privateFn.call(this);
        }
    };
}()

obj.publicFn()
// In the example above, privateFn is not exposed in obj but it can still be constructed as if it was a part of the public scope (using this in the same way).

// Bind
let name = {
    firstname: 'Rohit',
    lastname: 'Kuhar'
}
let printName = function() {
    console.log(this.firstname + ' ' + this.lastname)
}
let myName = printName.bind(name)
myName()