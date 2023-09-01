import { useForm } from "react-hook-form";
import { useState } from "react";
import './App.css';

function App() {
  const { register, handleSubmit, errors } = useForm();
  const [userInfo, setUserinfo] = useState();

  const onSubmit = (data) => {
    setUserinfo(data);
    console.log(data);
  };
  console.log(errors);

  return (
    <div className="container">
      <pre>{JSON.stringify(userInfo, undefined, 10)}</pre>
      <form onSubmit={handleSubmit(onSubmit)}>
        <h1>Registration Form</h1>
        <div className="ui divider"></div>
        <div className="ui form">
          <div className="field">
            <label>username</label>
            <input
              type="text"
              // name="username"
              placeholder="username"
              {...register('username', { required: true })}
            />
          </div>
          <div className="field">
            <label>email</label>
            <input
              type="email"
              // name="email"
              placeholder="email"
              {...register('email', {
                required: true,
                pattern: {
                  value: /^\S+@\S+\.\S+$/i,
                  message: "This is not a valid email",
                }
              })}
            />
          </div>
          <div className="field">
            <label>password</label>
            <input
              type="password"
              // name="password"
              {...register("password",
                {
                  required: "Password is mandatory",
                  minilength: {
                    value: 4,
                    message: "Password must be more than four characters",
                  },
                  maxlength: {
                    value: 10,
                    message: "Password must not exceed more than 10 characters",
                  }
                }
              )}
              placeholder="password"

            />
          </div>
        </div>
        <button className="fluid ui button red">Submit</button>
      </form>
    </div>
  );
}

export default App;
