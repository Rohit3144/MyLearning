const second = 1000;
const minute = 60 * second;
const hour = 60 * minute;
const day = 24 * hour;

function timerFunction() {
  setInterval(() => {
    const timer = new Date("02/07/2024").getTime();
    const today = new Date().getTime();
    
    const difference = timer - today;
    const leftDay = Math.floor(difference / day);
    const leftHour = Math.floor((difference % day) / hour);
    const leftMinute = Math.floor((difference % hour) / minute);
    const leftSecond = Math.floor((difference % minute) / second);

    console.log(`${leftDay} : ${leftHour} : ${leftMinute} : ${leftSecond}`);

    // console.log("timer: ", timer);
    // console.log("today: ", today);
    // console.log("difference: ", difference);
    // console.log('Days: ',Math.floor(difference / day));
    // console.log('Hours: ',Math.floor((difference % day) / hour));
    // console.log('Minutes: ',Math.floor((difference % hour) / minute));
    // console.log('Seconds: ',Math.floor((difference % minute) / second));
  }, 1000);
}

timerFunction();
