// // Generate a random color
// const randomColor = function() {
//     let hex = '0123456789ABCDEF'
//     let color = '#'
//     for(let i = 0; i < 10; i++) {
//         color += hex[Math.floor(Math.random() * 16)]
//         // console.log(color);
//     }
//     return color;
// }
// console.log(randomColor())
// // randomColor()

const randomColor = function () {
    const hex = '0123456789ABCDEF'
    let color = '#'
    for (let i = 0; i < 6; i++) {
        color += hex[Math.floor(Math.random() * 16)]
        // console.log(i)
    }
    console.log(color)
    return color;
    
};
//   console.log(randomColor());
//   randomColor();

let intervalId;

const startChangeColor = function () {
    if (!intervalId || intervalId === null) {
        intervalId = setInterval(bgColor, 1000)
        return intervalId;
    }
    function bgColor() {
        document.body.style.backgroundColor = randomColor();
    }
};

// const startChangeColor = setInterval(function () {
//     document.body.style.backgroundColor = randomColor();
// }, 1000);

document.querySelector('#start').addEventListener('click', startChangeColor);
//   console.log(startChangeColor())


const stopChangeColor = function () {
    clearInterval(intervalId)
    intervalId = null;
}
document.querySelector('#stop').addEventListener('click', stopChangeColor);