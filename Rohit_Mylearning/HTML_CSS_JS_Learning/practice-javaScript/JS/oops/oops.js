const user = {
    username: 'Rohit',
    laptop: 'Acer',
    lcoation: 'Gurugram',

    getUserDetails: function() {
        // console.log('User details are: ', username)
        console.log('User details are: ', this.username)
        console.log('this: ', this)
    }
}
console.log(user.username)
console.log(user.getUserDetails());

function user1(username, laptop, location) {
    this.username = username
    this.laptop = laptop
    this.location = location

    this.greeting = function() {
        console.log(`Welcome, ${this.username}`)
    }

    // return this;
}
//  if not writing new keyword then empty object will get printed e.g. {} 
const userOne = new user1('Rahul', 'hp', 'Sonipat')
const userTwo = new user1('Rohit', 'hppppp', 'Sonipattttt')

console.log('This is userOne: ',userOne)
console.log(userTwo)
// console.log(this)    // {}