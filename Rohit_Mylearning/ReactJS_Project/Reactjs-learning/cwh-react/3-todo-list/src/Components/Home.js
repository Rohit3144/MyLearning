import React, { useState } from "react";
import Task from "./Task";

function Home() {

    const [tasks, setTasks] = useState([])
    const [title, setTitle] = useState("")
    const [description, setDescription] = useState("");

    // console.log(title, description);

    const submitHandler = (e) => {
        e.preventDefault()
    }

    return (
      <div className="container">
        <h1>Daily Goals</h1>
        <form onSubmit={submitHandler}>
          <input type="text" placeholder="title" value={title} onChange={(e) => setTitle(e.target.value)}/>
          <textarea placeholder="description" value={description} onChange={(e) => setDescription(e.target.value)}/>
          <button type="submit">Add</button>
        </form>

        {tasks.map( () => (
            <Task />
        ) )}

      </div>
    );
}

export default Home;
