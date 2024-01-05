// WE can use for of loop on ("strings") and [Array].
// We can use for in loop on Objects, array and strings.
// We can use foreach loop on Arrays.

// ["string1", "string2", "string3"]
// [{object1}, {object2}, {object3}]

// const arr = [1, 2, 3, 4, 5]
// for (const num of arr) {
//     console.log(num)
// }

// const greeting = "Hello world"
// for (greet of greeting) {
//     if(greet == " ") {
//         break;
//     }
//     console.log(`Each character in greet is ${greet}`)
// }

// const myObj = {
//     js: 'javascript',
//     cpp: 'C++',
//     rb: 'ruby'
// }
// //TypeError: myObj is not iterable (due to for of loop)
// for (key of myObj) {
//     console.log(key)
// }

// for (key in myObj) {
//     console.log(key)
//     // TypeError: myObj is not a function
//     // console.log(myObj(key))
//     console.log(myObj[key])
// }

// const language = ["java", 'python', 'c', 'c++', 'javascript']
// for (lang in language) {
//     // it will print key (index) only
//     // console.log(lang)
//     console.log(language[lang])
// }

// ForEach loop
// const code = ["java", 'python', 'c', 'c++', 'javascript']
// code.forEach( function (val) {
//     console.log(val)
// } )
// // alternate of above loop
// code.forEach( (val) => {
//     console.log(val)
// } )

// // Alternate of above
// function print(item) {
//     console.log(item)
// }
// code.forEach(print)

const mylang = [
    {
        langName: "Javascript",
        langFile: "JS"
    },
    {
        langName: "RubyOnRails",
        langFile: "RR"
    },
    {
        langName: "Python",
        langFile: "PY"
    }
]
mylang.forEach( (item) => {
    // console.log(item.langName)
    console.log(item.langFile)
} )