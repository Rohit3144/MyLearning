const zodiac = document.getElementById("zodiac");

const body = document.body;
// body.style.backgroundColor = "#fc0303";

const changeBackground = () => {
  console.log(zodiac.value);
  switch (zodiac.value) {
    case "Aries":
      body.style.backgroundColor = "#fc0303";
      break;
    case "Leo":
      body.style.backgroundColor = "#eb8d03";
      break;
    case "Scorpio":
      body.style.backgroundColor = "#fc88d8";
      break;
    case "Virgo":
      body.style.backgroundColor = "#eb8d57";
      break;
    default:
      break;
  }
};
