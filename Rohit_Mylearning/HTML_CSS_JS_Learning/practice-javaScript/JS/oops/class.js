// class user{
//     constructor(username, email, password) {
//             this.username = username
//             this.email = email
//             this.password = password
//     }

//     encryptPassword() {
//         // console.log(`New Password: ${this.password}abc`)     // undefined
//         return `${this.password}abc`
//     }
//     changeUsername() {
//         return `${this.username.toUpperCase()}`
//     }
// }
// const a = new user('Rohit', 'rk@gmail', '123@')
// console.log(a.encryptPassword())
// console.log(a.changeUsername())

// Do it with Function(old way)
function user1(username, email, password) {
    this.username = username
    this.email = email
    this.password = password
}
user1.prototype.encryptPassword = function() {
    return `${this.password}abc`
}

user1.prototype.changeUsername = function() {
    return `${this.username.toUpperCase()}`   
}

const a1 = new user1('Rahul', 'rk@gmail', '123@')
console.log(a1.encryptPassword())
console.log(a1.changeUsername())