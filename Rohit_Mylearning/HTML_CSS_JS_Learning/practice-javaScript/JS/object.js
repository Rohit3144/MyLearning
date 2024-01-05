// Objects Two types - 1. Singleton object  2. Object literals
// Destructuring

const user = new Object()   // Singleton object
// console.log(user)
const user1 = {}    // non-singleton object

user1.id = '123asd'
user1.name = 'Rohit'

// console.log(user1)

const obj1 = {1: 'a', 2: 'b'}
const obj2 = {3: 'a', 4: 'b'}

// const newObj = Object.assign(obj1, obj2)    // To add two objects
const newObj = {...obj1, ...obj2}       // Spread operator
// console.log(newObj)

// De-Structure
const course = {
    coursename: 'js',
    price: '999',
    courseInstructor: 'Internet'
}
// console.log(course)
// const {courseInstructor} = course
// console.log(courseInstructor)
const {courseInstructor: instructor} = course
console.log(instructor)
