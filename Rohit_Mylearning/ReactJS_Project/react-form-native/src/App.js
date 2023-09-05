import './App.css';
import { useState } from "react";

function App() {
  const initialValue = { username: "", email: "", password: "" };
  const [formValues, setFormValues] = useState(initialValue);

  // console.log("formValue = ", formValues);

  // let count = 1;
  // const handleChange = () => {
  //   console.log("Rohit Kuhar", count++);
  // }

  function handleChange(e) {
    // console.log("Rohit Kuhar ==> ", e.target.value);
    const { name, value } = e.target;
    // console.log("name => ", name);
    // console.log("value => ", value);
    setFormValues({ ...formValues, [name]: value });
    // console.log("formValues => ", formValues);
  }

  return (
    <div className="container">
      <form>
        <h1>Login Form</h1>
        <div className="ui divider"></div>
        <div className="ui form">
          <div className="field">
            <label>username</label>
            <input
              type="text"
              name="username"
              placeholder="your name"
              value={formValues.username}
              onChange={handleChange}
            >
            </input>
          </div>
          <div className="field">
            <label>email</label>
            <input
              type="email"
              name="email"
              placeholder="your email"
              value={formValues.email}
              onChange={handleChange}
            >
            </input>
          </div>
          <div className="field">
            <label>password</label>
            <input
              type="password"
              name="password"
              placeholder="password"
              value={formValues.password}
              onChange={handleChange}
            >
            </input>
          </div>
          <button className="fluid ui button Black">Submit</button>
        </div>
      </form>
    </div>
  );
}

export default App;
