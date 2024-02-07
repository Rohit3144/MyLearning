// const url = "https://codebeautify.org/random-link-generator";

// console.log("a");

// const fetchData = () => {
//   fetch(url)
//     .then((response) => {
//       console.log(response);
//       return response.json();
//     })
//     .then((data) => {
//       console.log(data);
//     });
// };

// fetchData();
// console.log("z");


// Doing it using async await function
const urll = "https://catfact.ninja/fact";
// const h1 = document.querySelector("h1");

const fetchAgain = async () => {
  
  const data = await fetch(urll, {

  });
  console.log('data is: ',data)
  const response = await data.json();

//   h1.innerText = response;
console.log('cat lovers......')
console.log('The response is: ', response)
};

fetchAgain()

