// Syntactical Sugar Syntax
class Vehicle{
    constructor(company){
        this.company = company;
    }
}

class Car extends Vehicle{
    constructor(company, name, price){
        super(company);
        this.name = name;
        this.price = price;
    }
}

class Suv extends Car{
    constructor(company, name, price, type){
        super(company, name, price);
        this.type = type;
    }
}

let bmw = new Car("BMW", "E530d", 100);
console.log(bmw);

let scorpio = new Suv("Mahindra", "scorpio", 100, "Suv");
console.log(scorpio);