import { useState } from "react";


function App() {

  // Counter is a hook
  let [counter, setCounter] = useState(5)

  // let counter = 5
  
  const addValue = () => {
    // console.log("Value added", counter);
    // counter = counter + 1;

    // Difference between the below two paragraph outputs, Whether counter will be updated or not
    // setCounter(counter + 1)
    // setCounter(counter + 1)
    // setCounter(counter + 1)

    // setCounter(preCounter => preCounter + 1)
    // setCounter(preCounter => preCounter + 1)
    // setCounter(preCounter => preCounter + 1)
    // setCounter(preCounter => preCounter + 1)
    

    if(counter >= 20)
    {
      setCounter(counter)
      console.log("It won't go more than 20")
    }
    else {
      setCounter(counter + 1)
    }
  }

  const removeValue = () => {
    // console.log('Subtract value', counter)
    // counter = counter - 1;
    if(counter <= 0)
    {
      setCounter(counter)
      console.log("It won't go less than 0")
    }
    else {
      setCounter(counter - 1)
    }

  }

  return (
    <>
      <h1>This is hooks file</h1>
      <h2>Counter value: {counter}</h2>
      <button onClick={addValue}>Add {counter}</button>
      <button onClick={removeValue}>Subtract {counter}</button>
    </>
  )
}

export default App
