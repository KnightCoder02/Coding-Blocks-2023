const mongoose = require('mongoose');
const {Schema} = mongoose;

const studentSchema = new Schema({
    name:{
        type: String,
        required: true
    },
    age:{
        type: String,
        required: true
    },
    marks: Number,
    address_id:{
        type: Schema.Types.ObjectId,
        ref: 'address'
    }
});

module.exports = mongoose.model('students', studentSchema);

// [
//     {
//       _id: ObjectId('67937b55c7f64af191cb0ce2'),
//       details: 'Noida, Coding Blocks'
//     },
//     {
//       _id: ObjectId('67937b55c7f64af191cb0ce3'),
//       details: 'Pitampura, Coding Blocks'
//     },
//     {
//       _id: ObjectId('67937b55c7f64af191cb0ce4'),
//       details: 'Lucknow, Coding Blocks'
//     }
// ]

[
    {
        name: "Pratik",
        age: 18,
        marks: 40,
        address_id: ObjectId('67937b55c7f64af191cb0ce2')
    },
    {
        name: "Salman",
        age: 28,
        marks: 90,
        address_id: ObjectId('67937b55c7f64af191cb0ce3')
    },
    {
        name: "Dhairya",
        age: 48,
        marks: 100,
        address_id: ObjectId('67937b55c7f64af191cb0ce4')
    }
]