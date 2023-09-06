import './App.css';
import { useEffect, useState } from "react";
// import { useEffect };

function App() {
  const initialValue = { username: "", email: "", password: "" };
  const [formValues, setFormValues] = useState(initialValue);
  const [formErrors, setformErrors] = useState({});
  const [isSubmit, setIsSubmit] = useState(false);

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

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log("Submit ==> ", formValues);
    //Validate the form values
    setformErrors(validate(formValues));
    setIsSubmit(true);
  }

  useEffect(() => {
    console.log(formErrors);
    if (Object.keys(formErrors).length === 0 && isSubmit) {
      console.log(formValues);
    }
  }, [formErrors]);

  function validate(values) {
    const errors = {};
    // console.log("Validate ==> ", values);
    const regex_email = /^\S+@\S+\.\S+$/i;

    if (values.username === "") {
      errors.username = "username is required";
      // console.log(errors.username);
    }

    // email emptiness
    if (values.email === "") {
      errors.email = "Email is required";
    }
    // email validation
    else if (!regex_email.test(values.email)) {
      errors.email = "Email format is not valid";
      // console.log(errors.email);
    }
    if (values.password.length < 4 || values.password.length > 10) {
      errors.password = "Password length should be between 4 - 10 letters";
    }
    if (values.password === "") {
      errors.password = "password is required";
      // console.log(errors.password);
    }
    return errors;
  }

  return (
    <div className="container">
      {
        Object.keys(formErrors).length === 0 && isSubmit ?
        (<div className='ui message success'>Signed in Successfully</div>) :
        (<div>
          <div 
          className='ui message success'
            style={
            {
              color: "green",
              background: "yellow"
            }
          }>
            Failed attempt</div>
          <pre>{JSON.stringify(formValues, undefined, 2)}</pre>
        </div>)
      }

      {/* To display on the screen */}
      {/* <pre> {JSON.stringify(formValues, undefined, 4)} </pre> */}

      <form onSubmit={handleSubmit}>
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
          <p>{formErrors.username}</p>
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
          <p>{formErrors.email}</p>
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
          <p>{formErrors.password}</p>
          <button className="fluid ui button Black">Submit</button>
        </div>
      </form>
    </div>
  );
}

export default App;
