import React, { useState } from "react";

function Home() {

    const [inputValue, setInputValue] = useState(0)

    const changeHandler = (e) => {
      inputValue = e.target.value;
      console.log(inputValue);
    };

    const btnStyle = {
        padding: 20,
        border: 'none',
        backgroundColor: 'darkgrey',
        margin: 5
    }
    const increment = () => {
        setInputValue(inputValue + 1)
        //  console.log(e);
    }
    const decrement = () => {
        setInputValue(inputValue - 1)
        // console.log(e)
    };

    return (
    <>
      <input
        style={{ padding: 20, border: "2px solid green" }}
        type="number"
        placeholder="Enter some text"
        // onChange={changeHandler}
        value={inputValue}
        readOnly
      />
      <button style={btnStyle} onClick={increment}>
        +
      </button>
      <button style={btnStyle} onClick={decrement}>
        -
      </button>
    </>
  );
}

export default Home;
