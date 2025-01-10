let inp = document.querySelector('.inp');
let btn = document.querySelector('.btn');
let taskList = document.querySelector('.taskList');

btn.addEventListener('click', () => {
    let taskName = inp.value;
    let li = document.createElement('li');
    li.innerHTML = 
        `<span class="taskText">${taskName}</span>
        <button class="upBtn">⬆</button>
        <button class="downBtn">⬇</button>
        <button class="deleteBtn">❌</button>`;
        li.classList.add('taskItem');
    taskList.appendChild(li);
    inp.value = "";
})

taskList.addEventListener('click', (ev) => {
    let item = ev.target;
    if(item.classList.contains('upBtn')){
        console.log("Pressed Up Button");
        let parentElement = item.parentElement;
        let previousElement = parentElement.previousElementSibling;
        taskList.insertBefore(parentElement, previousElement);
        console.log(parentElement);
        console.log(previousElement);
    }
    else if(item.classList.contains('downBtn')){
        console.log("Pressed Down Button");
        let parentElement = item.parentElement;
        let nextElement = parentElement.nextElementSibling;
        taskList.insertBefore(nextElement, parentElement);
    }
    else if(item.classList.contains('deleteBtn')){
        console.log("Pressed Delete Button");
        let parentElement = item.parentElement;
        parentElement.remove();
    }
})