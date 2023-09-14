import React, { useEffect, useState } from "react";
import { v4 as uuid } from "uuid";
import "./App.css";
import Header from "./Header";
import AddContact from "./AddContact";
import ContactList from "./ContactList";

// const contactList = [
//   {
//     id: "1",
//     name: "Rohit",
//     email: "abc@gmai.com"
//   },
//   {
//     id: "2",
//     name: "Kuhar",
//     email: "qwe@gmail.com"
//   }
// ]

// const addConactHandler = (contacts) => {
//   console.log("contacts => ", contacts);
// }

function App() {

  const LOCAL_STORAGE_KEY = "RohitContacts";
  const [contacts, setContacts] = useState([]);

  const addConactHandler = (c) => {
    console.log("contacts => ", c);
    setContacts([...contacts, { id: uuid(), ...c }]);
  };

  useEffect(() => {
    const retriveContacts = JSON.parse(localStorage.getItem(LOCAL_STORAGE_KEY));
    if (retriveContacts.length) {
      setContacts(retriveContacts)
    }
  }, []); // [] is called once when page is refreshed


  useEffect(() => {
    localStorage.setItem(LOCAL_STORAGE_KEY, JSON.stringify(contacts));
  }, [contacts]); // it will be called when "contacts" get updated

  const removeContactHandler = (id) => {
    const newContactList = contacts.filter((c) => {
      return c.id !== id;
    })
    setContacts(newContactList);
  }

  return (
    <div className="ui container" >
      <Header />
      <AddContact myAddContactHandler={addConactHandler} />
      <ContactList mycontacts={contacts} getContactId={removeContactHandler} />
    </div >

  );
}

// function App() {
//   const LOCAL_STORAGE_KEY = "contacts";
//   const [contacts, setContacts] = useState(
//     JSON.parse(localStorage.getItem(LOCAL_STORAGE_KEY)) ?? []
//   );

//   const addContactHandler = (contact) => {
//     console.log("contact => ", contact);
//     setContacts([...contacts, {id: uuid(), ...contact}]);
//   };

//   const removeContactHandler = (id) => {
//     const newContactList = contacts.filter((contact) => {
//       return contact.id !== id;
//     });
//     setContacts(newContactList);
//   };

//   // useEffect(() => {
//   //   const retriveContacts = JSON.parse(localStorage.getItem(LOCAL_STORAGE_KEY));
//   //   console.log(retriveContacts);
//   //   if(retriveContacts)
//   //     setContacts(retriveContacts);
//   // }, []);

//   useEffect(() => {
//     localStorage.setItem(LOCAL_STORAGE_KEY, JSON.stringify(contacts));
//   }, [contacts]);

//   return (
//     <div className="ui container">
//       <Header />
//       <AddContact myAddContactHandler={addContactHandler} />
//       <ContactList myContacts={contacts} getContactId={removeContactHandler} />
//     </div>
//   );
// }

export default App;
