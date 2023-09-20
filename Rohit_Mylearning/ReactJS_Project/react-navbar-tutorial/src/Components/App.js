import './App.css';
import { BrowserRouter, Route, Routes } from "react-router-dom";
import Navbar from "./Navbar/Navbar";
import Home from "./Pages/Home";
import KeyFeatures from "./Pages/KeyFeatures";
import Pricing from "./Pages/Pricing";
import Testimonials from "./Pages/Testimonials";
import Demo from "./Pages/Demo";

function App() {
  return (
    <div className="container">
      {/* <header className="App-header">
      Hi.....
      </header> */}
      <BrowserRouter>
        <Navbar />
        <Routes>
          <Route path="/" Component={Home} />
          <Route path="/features" Component={KeyFeatures} />
          <Route path="/pricing" Component={Pricing} />
          <Route path="/testimonials" Component={Testimonials} />
          <Route path="/demo" Component={Demo} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;