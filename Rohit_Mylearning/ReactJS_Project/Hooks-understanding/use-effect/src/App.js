import './App.css';
import CComponent from './CComponent';
import FComponent from './FComponent';
import React, { useState } from 'react';

function App() {

  const [cflag, setCflag] = useState(true);

  // function togglebutton () {

  // // }

  // const togglebutton = () => {
  //   setCflag(!cflag);
  // }

  return (
    <div className="App">
      <hr></hr>
      <h1>Hello, This is App component</h1>
      <button onClick={() => setCflag(!cflag)}>Toggle the component</button>
      <hr></hr>
      {cflag ? <CComponent /> : <FComponent />}


    </div>
  );
}

export default App;
