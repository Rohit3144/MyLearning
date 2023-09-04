import './App.css';

function App() {
  return (
    <div className="container">
      <form>
        <h1>Login Form</h1>
        <div className="ui divider"></div>
        <div className="ui form">
          <div className="field">
            <label>username</label>
            <input type="text" name="username" placeholder="your name">
            </input>
          </div>
          <div className="field">
            <label>email</label>
            <input type="email" name="email" placeholder="your email">
            </input>
          </div>
          <div className="field">
            <label>password</label>
            <input type="password" name="password" placeholder="password">
            </input>
          </div>
          <button className="fluid ui button Black">Submit</button>
        </div>
      </form>
    </div>
  );
}

export default App;
