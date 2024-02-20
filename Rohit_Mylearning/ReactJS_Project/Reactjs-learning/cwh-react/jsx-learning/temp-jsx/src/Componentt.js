const Componentt = () => {
  const name = "Rohit";

  // JSX with styling
  const style = {
    color: "blue",
    fontSize: "30px",
    textAlign: "center",
  };

  //   return (
  //     <>
  //       <h1 style={style}>Hi, {name}</h1>
  //       <h1>This is new component</h1>
  //     </>
  //   );

  // // 2.  JSX with Conditional rendering
  // const isLogin = true;

  // return (
  //   <>
  //     {isLogin ? (
  //       <h1 style={style}>Hi, {name}</h1>
  //     ) : (
  //       <h1>Log in to continue......This is new component</h1>
  //     )}
  //   </>
  // );

  //   // 3. List in JSX
  //   const numbers = [11, 22, 33, 44, 55];
  //   return (
  //     <>
  //       <ul>
  //       {numbers.map((number) => (
  //         <li>{number}</li>
  //       ))}
  //       </ul>
  //     </>
  //   );

  //  4. Handling Events in JSX
  const items = [11, 22, 33, 44, 55];

  const handleClick = (item) => {
    console.log(`Clicked on: ${item}`);
  };
  return (
    <>
      <ul>
        {items.map((item, index) => (
          <li key={index} onClick={() => handleClick(item)}>
            {item}
          </li>
        ))}
      </ul>
    </>
  );
};

export default Componentt;
