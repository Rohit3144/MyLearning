import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App.jsx'

function MyApp() {
  return (
    <h2>This is MyApp !!</h2>
  )
}

// We can not use this object in react (Syntactic problem)
// const ReactElement = {
//     type: 'a',
//     props: {
//         href: 'https://google.com',
//         target: '_blank'
//     },
//     children: 'Click me to visit google'
// }

// We can use this type of object in React (Syntactically right)
const anotherElement = (
  <a href='https://google.com' target='www.google.com'>Visit Google</a>
)

const reactElement = React.createElement(
  'a',
  {href: 'https://google.com', target: '_blank'},
  'click me to visit google',
  // anotherElement
)

ReactDOM.createRoot(document.getElementById('root')).render(

  <App/>
)
