import React, { useEffect, useState } from "react";

function FComponent() {
    const [message, setMessage] = useState("Function Component");
    const [time, setTime] = useState(new Date().toString());

    function showDate() {
        setTime(new Date().toString());
    }

    useEffect(() => {
        console.log("Component mount or updated");
        // Initialization
        const interval = setInterval(showDate, 1000);

        // Cleanup
        return () => {
            clearInterval(interval);
        }
    }, [time, message] /* Dependency */);

    function changeMessage() {
        setMessage("I am Kuhar ", Math.floor((Math.random() * 100) + 1));    //1 to 100 range
    }

    return (
        <div>
            <h1>This is Function component</h1>
            <button onClick={changeMessage}>Change Content</button>
            <button onClick={showDate}>show date</button>
            <h2>{message}</h2>
            <div>{time}</div>
        </div>
    );

}

export default FComponent;