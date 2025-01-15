const express = require('express')
const path = require('path');
const app = express()
const port = 3000;

let publicPath = path.join(__dirname, "public");
app.use(express.static(publicPath));

app.get('/gettask', (req, res) => {
    const {task} = req.query;
    res.send(task);
})

app.listen(port, () => {
    console.log(`http://localhost:${port}`);
});    //This will start the server