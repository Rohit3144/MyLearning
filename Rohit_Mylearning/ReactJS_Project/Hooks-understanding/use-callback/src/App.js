import './App.css';
import React, { useState, useMemo, useEffect, useCallback } from "react";


function App() {
  const [counter, setCounter] = useState(1);
  const [name, SetName] = useState("");

  let result = useMemo(() => {
    return factorial(counter);
  }, [counter]);

  // const displayName = () => {
  //   return name;
  // }

  const displayName = useCallback((greeting) => {
    return greeting + " " + name;
  }, [name])

  return (
    <div className="App">
      <h1>
        Factorial of {counter} is : <span>{result}</span>
      </h1>
      <button onClick={() => setCounter(counter + 1)}>Increment</button>
      <button onClick={() => setCounter(counter - 1)}>Decrement</button>
      <hr />
      <div>
        <div>
          <label>Enter Name</label>
        </div>
        <input
          type="text"
          name="name"
          placeholder="Enter your name"
          onChange={(e) => SetName(e.target.value)}
        >
        </input>
        <hr></hr>
        <DisplayName displayName={displayName} />

        {/* <button></button> */}
      </div>
    </div>
  );
}

const DisplayName = (({ displayName }) => {
  const [value, setValue] = useState();

  useEffect(() => {
    setValue(displayName());
    console.log("name ==> displayName Hits");
  }, [displayName])
  
  return <p>{`My name is ${value}`}</p>
})

function factorial(n) {
  let i = 0;
  while (i < 2000000)
    i++;

  if (n < 0)
    return -1;
  if (n === 0)
    return 1;

  return n * factorial(n - 1);
}

export default App;
