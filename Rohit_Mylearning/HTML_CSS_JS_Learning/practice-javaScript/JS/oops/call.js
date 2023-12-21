function user(username) {
    console.log('called ')
    this.username = username
}
function newUser(username, email, pswd) {
    user.call(this, username)
    // this.username = username
    this.email = email
    this.pswd = pswd
}
const calledUser = new newUser('RK', 'mail.com', 111)
console.log(calledUser)
console.log(calledUser.username)

