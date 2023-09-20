import React from "react";
import { MenuList } from "./MenuList";

const Navbar = () => {
    const menulist = MenuList.map(({title, url}, index) => {

        return (
            <li key={index}>
                <a href={url}>{title}</a>
            </li>
        )
    })

    return (
        <nav>
            <div className="logo">
                VPN<font>Lab</font>
            </div>
            <ul className="menu-list">
                {menulist}
            </ul>
        </nav>
    )
}

export default Navbar;