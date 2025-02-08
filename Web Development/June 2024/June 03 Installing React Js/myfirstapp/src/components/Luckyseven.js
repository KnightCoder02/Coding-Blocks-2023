import React from 'react'
import './Luckyseven.css';

let winningGif = 'https://media4.giphy.com/media/3ohryhNgUwwZyxgktq/giphy.gif?cid=6c09b952ubgodyg2i2hf4hr77716k43nd4fuxs1juoym94s8&ep=v1_gifs_search&rid=giphy.gif&ct=g'
let losingGif = 'https://media1.giphy.com/media/mcH0upG1TeEak/giphy.gif?cid=6c09b952vsez4qz0aq7mdquhtmo0vndxa8m8vxixl4k780bc&ep=v1_gifs_search&rid=giphy.gif&ct=g'

const Luckyseven = () => {
    let randomNumber = Math.floor( Math.random() * 10 + 1);
    return (
        <div>
            <h3 className='luckySevenHeading'>LuckySeven</h3>
            <div className='luckyNumber'>Lucky number is : {randomNumber}</div>
            {randomNumber == 7 && <img className='img' src={winningGif}/>}
            {randomNumber != 7 && <img className='img' src={losingGif}/>}
        </div>
    )
}

export default Luckyseven;