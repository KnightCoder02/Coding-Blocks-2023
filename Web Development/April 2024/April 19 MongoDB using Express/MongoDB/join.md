#Learning to apply joins in mongodb
1. create students collection
2. create address collection

Syntax:
- db.collectionName.insertMany([]);
    > db.address.insertMany([{details: "Delhi, India"}, {details: "Shahdara, Delhi"}, {details: "Dilshad Garden, Delhi"}]);

<!-- {
    $lookup:
    {
        from: <collection to join>,
        localField: <field from the input documents>,
        foreignField: <field from the documents of the "from" collection>,
        as: <output array field>
    }
} -->

> db.students.aggregate([{$lookup:{from: "address", localField: "a_id", foreignField: "_id", as: "AddressDetails"}}]);