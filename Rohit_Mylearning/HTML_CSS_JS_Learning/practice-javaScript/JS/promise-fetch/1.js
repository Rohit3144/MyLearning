const promiseOne = new Promise(function(resolve, reject) {
    // Do any async task
    // Database, Cryptography, Network 
    setTimeout( function () {
        console.log('Async task is done here')
        resolve()
    }, 1000);
} )
promiseOne.then(function () {
    console.log('Promise completed')
})

// Second option for promise without taking a variable
new Promise( function(resolve, reject) {
    setTimeout( function() {
        console.log('This is Async 2')
        resolve()
    }, 1000)
}).then( function() {
    console.log('Async 2 resolved')
})

// How to take data in promise
new Promise( function(resolve, reject) {
    setTimeout( function() {
        console.log('This is Async 3')
        resolve({username: 'Rohit', email: 'rk@rohit.com'})
    }, 1000)
}).then( function(user) {
    console.log(user)
})

// Using resolve and reject with catch and finally
new Promise( function(resolve, reject) {
    setTimeout( function() {
        let error = true;
        if(!error) {
        resolve({username: 'Rahul', email: 'rk@rahul.com'})
        } else {
            reject('Error poped up')
        }
    }, 1000)
}).then( function(user) {
    console.log(user)
    return user.username;
})
.then( (username => console.log(username)) )
.catch( (error) => console.log(error) )
.finally( () => {
    console.log('Promise either resolved or rejected')
} )

// Using Async Await function with Promise
const five = new Promise( function(resolve, reject) {
    setTimeout( function() {
        console.log('This is Async 5')
        resolve({username: 'Rahul', email: 'rk@rahul.com'})
    }, 1000)
})
async function promiseFive() {
    try {
    const response = await five
    console.log('This is Async await function: \n',response)
    }   catch(error) {
        console.log('Error: ', error)
    }
}
promiseFive()

// We can use try and catch init
async function getUsers() {
    try {
    const response = await fetch('https://jsonplaceholder.typicode.com/users')
    // console.log(response)
    // If await is not using in below line then JS compiler will not wait for the data and compile the next lines
    const data = await response.json()
    console.log(data)
    } catch(error) {
        console.log('E: ',error)
    }
}
getUsers()

// OR part of just above async await code by using then() and catch()
fetch('https://jsonplaceholder.typicode.com/users')
.then( (response) => { 
    return response.json() 
} )
.then( (data) => console.log(data) )
.catch( (error) => console.log(error) )