const path = require('path');

const express = require('express');
const app = express();

const http = require('http');
const server = http.createServer(app);
let port = 3000;

const socketio = require('socket.io');
const io = socketio(server);

let users = [];

// Server connection
io.on('connection', (socket) => {
    console.log("Connection is established");
    
    socket.on('login', (data) => {
        users[socket.id] = data.username;
    })
    
    socket.on('send-msg', (data) => {
        // This makes connection with one client
        // socket.emit('received-msg', {
        
        // This makes connection with all clients
        io.emit('received-msg', {
            msg: data.msg,
            username: users[socket.id]
        })    
    })
})

// Serving static files
app.use('/', express.static(path.join(__dirname, 'public')));

server.listen(port, () => {
    console.log(`Server connected at port: ${port}`)
})