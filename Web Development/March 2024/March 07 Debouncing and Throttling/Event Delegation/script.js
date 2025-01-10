let itemList = document.querySelectorAll('.item');
let container = document.querySelector('.container');
console.log(itemList);

// itemList.forEach((item) => {
//     item.addEventListener('click', () => {
//         console.log(item.innerText);
//     })
// })

container.addEventListener('click', (event) => {
    let item = event.target;
    console.log(item.innerText);
})