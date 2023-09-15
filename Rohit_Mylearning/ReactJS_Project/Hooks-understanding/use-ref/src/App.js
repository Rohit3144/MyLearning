import './App.css';
import { useEffect, useRef, useState } from "react";

function App() {

  const [name, setName] = useState(0);
  const [counter, setCounter] = useState(Math.ceil(Math.random() * 100));  // useState(0) --> it will start from 0
  let previousRandNum = useRef();

  let inputRef = useRef("");  // useRef("") or useRef(null) --> same

  function resetInput() {
    setName("");
    inputRef.current.focus();  // pointer will come in the input section due to focus
  }

  useEffect(() => {
    previousRandNum.current = counter;
  }, [counter])

  return (
    <div className="App">
      <hr></hr>
      <input
        ref={inputRef}
        type="text"
        name="name"
        autocomplete="on"
        value={name}
        onChange={(e) => setName(e.target.value)}
      >
      </input>
      {/* <button onClick={() => setName("")}>Reset</button> No need of function resetInput */}
      <button onClick={resetInput}>Reset</button>
      <hr></hr>
      <hr></hr>
      <h1>Random Counter : {counter}</h1>
      {
        typeof previousRandNum.current != "undefined" &&
        <h2>Previous Random number = {previousRandNum.current}</h2>
      }
      <button onClick={() => setCounter(Math.ceil(Math.random() * 100))}>Random Generator</button>
      <hr></hr>
    </div>
  );
}

export default App;
