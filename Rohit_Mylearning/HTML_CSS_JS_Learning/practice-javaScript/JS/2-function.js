    // a();

    // // Function statement
    // function a() {
    //     console.log("This is function statement");
    // }

    // // Function expression
    // // b();    // Error will be (Uncaught TypeError: b is not a function)
    // var b = function () {
    //     console.log("This is function expression");
    // }
    // b();

    var b = function (param_value) {
        console.log("This is in variable b");
        param_value();
    }
    // calling anonymous function
    b(function () {
        console.log("This is function calling");
    });
    // calling parameter as function
    b(function param() {
        console.log("This is param function");
    });

    // function x(t) {
    //     console.log("Hello x function");
    //     t();
    // }
    // x(function y() {
    //     console.log("Hello function y");
    // })
