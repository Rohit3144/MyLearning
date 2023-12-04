// Window is the global object in browser
const user = {
    username: "Rohit",
    price: 999,
    welcomeMessage: function() {
        console.log(`${this.username}, welcome to javascript`)
        // console.log(this)
    }
}
user.welcomeMessage()
user.username = "Rahul"
user.welcomeMessage()
// It will return an empty object
// console.log(this)

// function one() {
//     console.log(this)
// }
// one()
