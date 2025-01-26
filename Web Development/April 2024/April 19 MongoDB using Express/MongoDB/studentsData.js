`
'0': ObjectId('67923c00a493f5eeaacb0ce2'),
'1': ObjectId('67923c00a493f5eeaacb0ce3'),
'2': ObjectId('67923c00a493f5eeaacb0ce4')
`

let students = [
    {
        name: 'Manav',
        age: 25,
        subject: 'Web Development',
        marks: 80,
        a_id: ObjectId('67923c00a493f5eeaacb0ce2')
    },
    {
        name: 'Vashu',
        age: 23,
        subject: 'SSC',
        marks: 70,
        a_id: ObjectId('67923c00a493f5eeaacb0ce3')
    },
    {
        name: 'Yogi',
        age: 24,
        subject: 'Navi',
        marks: 90,
        a_id: ObjectId('67923c00a493f5eeaacb0ce4')
    }
]

db.students.insertMany([{name: 'Manav', age: 25, subject: 'Web Development', marks: 80, a_id: ObjectId('67923c00a493f5eeaacb0ce2')}, {name: 'Vashu', age: 23, subject: 'SSC', marks: 70, a_id: ObjectId('67923c00a493f5eeaacb0ce3')}, {name: 'Yogi', age: 24, subject: 'Navi', marks: 90, a_id: ObjectId('67923c00a493f5eeaacb0ce4')}]);