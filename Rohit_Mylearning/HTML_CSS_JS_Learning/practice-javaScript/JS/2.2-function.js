const user = {
    username: "Rohit",
    price: "999"
}
function handleObjects(anyobject) {
    console.log(`username is ${anyobject.username} and price is ${anyobject.price}`)
}
// handleObjects({
//     username: "Rahul",
//     price: 999
// })
// handleObjects(user)

function x() {
    var a = 7
    function y() {
        console.log(a)
    }
    // console.log(q)
    return y
}
var z = x()
console.log(z)
z()
