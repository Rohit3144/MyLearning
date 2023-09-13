import './App.css';
import { React, useState } from "react";

function App() {
  // let name="Rohit";
  const [name, setName] = useState("Rohit");
  const [flag, setFlag] = useState(false);
  const [steps, setSteps] = useState(0);
  const [names, setNames] = useState([]);

  function changeName() {
    console.log("I clicked");
    console.log("Name before => ", name);
    setName("Kuhar");
    console.log("Name after => ", name);
    setFlag(!flag);
    // console.log(name);
    return;
  };

  function increment() {
    setSteps((e) => e + 1);
    setSteps((e) => e + 1);
  }

  function decrement() {
    setSteps(steps - 1);
  }

  function addNames(e) {
    e.preventDefault();   //Prevent from refreshing the page
    setNames([...names, { id: names.length, name }]);
    console.log("names => ", names);
  }

  return (
    <div className="App">
      <h1>Hello {flag ? name : "???"}</h1>
      <button onClick={changeName}>click me</button>
      <hr></hr>
      <button onClick={increment}>+</button>
      <h2>{steps}</h2>
      <button onClick={decrement}>-</button>
      <hr></hr>
      <form onSubmit={addNames}>
        <input
          type="text"
          name="name"
          placeholder='add names'
          onChange={(e) => setName(e.target.value)}
        >
        </input>
        <div>
          <button>submit</button>
        </div>
      </form>
      <hr></hr>
      <ul>{names.map((item) => (
        <li>{item.name}</li>
      ))}
      </ul>
    </div>
  );
}

export default App;
