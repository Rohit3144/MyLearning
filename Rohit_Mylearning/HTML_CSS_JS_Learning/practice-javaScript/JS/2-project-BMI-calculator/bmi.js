const form = document.querySelector('form')
const calculate = document.querySelector('calculate')

form.addEventListener('submit', function (e) {
    e.preventDefault()
    const height = parseInt(document.querySelector('#height').value)
    const weight = parseInt(document.querySelector('#weight').value)
    const result = document.querySelector('#results')

    if(height === '' || height < 0 || isNaN(height)) {
        result.innerHTML = `${height}, Please give a valid height`;
        // result.innerHTML = 'Please give a valid height';
    }
    else if(weight === '' || weight < 0 || isNaN(weight)) {
        result.innerHTML = '${weight}, Please give a valid weight'
    }
    else {
        // const bmi = (weight / ((height * height) / 10000)).toFixed[2]
        // const bmi = (weight/(height*2)/10000)
        const bmi = (weight/(height*2)) * 7
        
        // Show the results
        result.innerHTML = `${bmi}`
    }
    })