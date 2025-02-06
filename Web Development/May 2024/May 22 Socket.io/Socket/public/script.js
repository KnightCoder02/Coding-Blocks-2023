const socket = io();

$('#chat-box').hide();

$('#login-btn').on('click', function(){
    const username = $('#username').val();
    
    // Event Triggered
    socket.emit('login', {username: username});
    
    $('#username').hide();
    $('#login-btn').hide();
    $('#chat-box').show();
    
    $('#username').val("");
})

$('#send-btn').on('click', function(){
    const msgText = $('#inp').val();

    // Event Triggered
    socket.emit('send-msg', {msg: msgText});
    $('#inp').val("");
})

socket.on('received-msg', (data) => {
    $('#chat').append(`<li class="border p-2 ms-0 mb-2 rounded-pill"><span class="fw-bold">${data.username}: ${data.msg}</span></li>`)
})