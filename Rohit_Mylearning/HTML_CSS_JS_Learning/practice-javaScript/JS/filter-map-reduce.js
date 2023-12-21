// Filter -- it returns value
const num = [1,2,3,4,5,6,7,8,9]
// const newNum = num.filter( (n) => n > 4 );
// console.log(newNum)

// ForEach loop as filter
// newNum = []
// num.forEach( (n) => {
//     if(n>4) {
//         newNum.push(n)
//     }
// } )
// console.log(newNum)

// Map -- It also return
// const newNum = num.map( (n) => n * 10 )
// console.log(newNum)

// ForEach use as Map()


// Reduce -- here 0 is taken as initial value
const newNum = num.reduce(function (acc, currval) {
    return acc + currval
}, 0)
// console.log(newNum)

const user = [
    { fn: "Rohit", ln: "Kuhar", location: 'India' },
    { fn: "Donald", ln: 'Trump', location: 'USA' },
    { fn: 'Narender', ln: 'Modi', location: 'India'}
]

// Reduce
const output = user.reduce( function (acc, curr)  {
    if(acc[curr.location])
    {
        acc[curr.location] = ++acc[curr.location]
    }
    else {
        acc[curr.location] = 1
    }
    return acc;
},  {} )
// console.log(output)

// Filter
const filterOutput = user
            .filter( (x) => (x.location == "India") )
            .map( (x) => (x.fn) )
console.log(filterOutput)
            
