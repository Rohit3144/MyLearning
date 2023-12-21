// function multi(num) {
//     return num*5
// }
// multi.power = 2;

// function createUser(username, score) {
//     this.username = username
//     this.score = score
// }

// createUser.prototype.increment = function() {
//     this.score++;
//     console.log('hi')
// }
// const tea = new createUser('tt', 20)
// const tea1 = new createUser('tttt', 2000)

// tea.increment()
// // console.log(tea)
// // console.log(tea1)

// console.log(multi.power)
// console.log(multi(10));
// console.log(multi.prototype)


// // Another part
// let myHeros = ["thor", "spiderman"]

// let heroPower = {
//     thor: 'Hammer',
//     spiderman: 'Sling',

//     getSpiderPower: function() {
//         console.log(`Spider power is ${this.spiderman}`)
//     }
// }

// Object.prototype.Rohit = function() {
//     console.log("Rohit is present in all objects")
// }

// Array.prototype.Rahul = function() {
//     console.log('Rahul is present is array only')
// }

// myHeros.Rahul()
// // heroPower.Rahul()   // TypeError: heroPower.Rahul is not a function
// myHeros.Rohit()
// heroPower.Rohit()
// heroPower.getSpiderPower()
// console.log(heroPower)

// Inheritance
const User = {
    name: "chai",
    email: "chai@google.com"
}

const Teacher = {
    makeVideo: true
}

const TeachingSupport = {
    isAvailable: false
}

const TASupport = {
    makeAssignment: 'JS assignment',
    fullTime: true,
    __proto__: TeachingSupport
}

Teacher.__proto__ = User

// Modern syntax
Object.setPrototypeOf(TeachingSupport, Teacher) // Teacher is inherited by TeachingSupport

// console.log()
// console.log(TASupport)
console.log(TeachingSupport.__proto__)
console.log(TeachingSupport)
// console.log(TeachingSupport.__proto__)   // Because only TASupport inherited the TeachingSupport
// console.log(TeachingSupport.TASupport)   // Error

let anotherUserName = 'Rohit    '
String.prototype.trueLength = function() {
    console.log(`True length is ${this.trim().length}`)
}
console.log(anotherUserName.length)
anotherUserName.trueLength()