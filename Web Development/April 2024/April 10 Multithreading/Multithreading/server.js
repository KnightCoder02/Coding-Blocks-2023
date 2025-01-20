const express = require('express');
const cluster = require('cluster');
// Cluster module helps us to create multiple instance of node
const os = require('os');
const app = express();

// No. of cores =>
let totalCpus = os.cpus().length;
let platform = os.platform();

console.log(process.pid);
console.log(cluster.isPrimary); //This will tell me if I am on main thread
if(cluster.isPrimary){
    // total cpus = no. of cores = 12
    console.log('This is my main thread'); //This will tell me if I am on main thread
    for(i = 0; i < totalCpus; i++){
        cluster.fork();
    }
}
else{
    console.log(totalCpus, platform);

    app.get('/', (req, res) => {
        res.json({hi: ' response from node instance ${process.pid}'})
    })

    app.get('/slowApi', (req, res) => {
        for(let i = 0; i < 10_000_000_000; i++){}
        res.json({blocking: ' response from node instance ${process.pid}'});
    })

    app.listen(4000);
}