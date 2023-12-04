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
console.log(newNum)
