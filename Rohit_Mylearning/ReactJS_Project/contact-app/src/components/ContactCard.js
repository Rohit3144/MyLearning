import React from "react";
import avatar from "../images/avatar.jpg";

const ContactCard = (props) => {
    const { id, name, email } = props.mycontact;
    const url = "https://source.unsplash.com/1600x900/?nature,water"

    return (
        <div className="item">
           <div><img className="ui avatar image" src={url} alt="No image"/> </div>
            {/* <img className="ui avatar image" src={url} alt="No image"/>  */}
            <div> hellow</div>
            <div className="header">{id}</div>
            <div className="header">{name}</div>
            <img className="ui avatar image" src={avatar} alt="No image"/>
            <div>{email}</div>
            {/* <div>{email}</div> */}
            <i
                className="trash alternate outline icon"
                
                >
            </i>
        </div>
    );
}

// const ContactCard = (props) => {
//   const { id, name, email } = props.myContact;
//   console.log("My Contact => ", props.myContact);
//   return (
//     <div className="item">
//       <img className="ui avatar image" src={avatar} alt="avatar" />
//       <div className="container">
//         <div className="header" >{name}</div>
//         <div>{email}</div>
//         <i
//           className="trash alternate outline icon"
//           style={
//             {
//               color: "green",
//               // marginLeft: "20px",
//               // paddingLeft: "20px",
//               float: "right"
//             }
//           }
//           onClick={() => props.clickHandler(id)}
//         ></i>
//       </div>
//     </div>
//   );
// };

export default ContactCard;