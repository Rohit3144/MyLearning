function x() {
    for(var i=1; i<5; i++) {
        
        function close() {
            setTimeout(function() {
                console.log(i)
            }, 3000)
        }
         console.log("Hello....");
         return close;
    }
}
let z = x();
z();
z();
z();
z();
