import React from "react";

class CComponent extends React.Component
{
    state={
        message: "Class Component",
        time: new Date().toString(),
    }

    componentDidMount() {
        console.log("I am from Did mount");
        this.interval = setInterval(this.showDate, 1000);        
    }

    componentDidUpdate() {
        console.log("I am from update");
    }

    componentWillUnmount() {
        console.log("I am from unmount");
        clearInterval(this.interval);
    }

    showDate = () => {
        this.setState({time: new Date().toString()});
    }

    render () {
        return (
            <div>
                <h1>This is Class component</h1>
                <h2>{this.state.message}</h2>
                <div>{this.state.time}</div>
            </div>
        );
    }
}

export default CComponent;