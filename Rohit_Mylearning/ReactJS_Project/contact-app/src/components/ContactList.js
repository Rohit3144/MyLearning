import React from "react";
import ContactCard from "./ContactCard";

const ContactList = (props) => {

   const deleteContactHandler = (id) => {
        props.getContactId(id);
    }

    const renderContactList = props.mycontacts.map((contact) => {
        return (
            <ContactCard
                mycontact={contact}
                clickHandler={deleteContactHandler}
                key={contact.id}/>
        );
    });
    return <div className="ui celled list"> {renderContactList}</div>
    // return(

    // To print email only
    // console.log("mycontacts = ", props.mycontacts[0].email),


    //     <div className="ui celled list">
    //         <h1>Contact list</h1>
    //         {/* <hr></hr> */}
    //     </div>
    // );
}

// const ContactList = (props) => {
//     console.log("props = >", props);

//     const deleteContactHandler = (id) => {
//         props.getContactId(id);
//     }

//     const renderContactList = props.myContacts.map((contact) => {
//         return (
//             <ContactCard 
//                 myContact={contact}
//                 clickHandler={deleteContactHandler}
//                 key={contact.id}
//             />
//         );
//     })
//     return <div className="ui celled list">{renderContactList}</div>
// }

export default ContactList;