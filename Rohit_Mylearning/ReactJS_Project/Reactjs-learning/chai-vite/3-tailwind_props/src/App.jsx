import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import Card from './components/Card'

function App() {
  const [count, setCount] = useState(0)
  let myObj = {
    username: 'Rohit',
    age: 10
  }
  
  return (
    <>
      <h1 className='bg-green-400 text-yellow p-40'>Tailwind Test</h1>
      {/* <Card channel='Chaiaurcode' someObj={myObj}/> */}
      <Card channel='Chaiaurcode' btnText='click me'/>
      <Card channel='HiteshChaudhary' btnText='Visit us'/>
    </>
  )
}

export default App
