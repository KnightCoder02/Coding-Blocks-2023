class Student{
    constructor(name, age,marks){
        this.name = name;
        this.marks = marks;
        this.isAdult = function(){
            return age >= 18;
        }
    }

    printDetails(){
        console.log(`Name: ${this.name}, Age: ${this.age}, Marks :${this.marks}`);
    }
}

let manav = new Student("Manav", 24, 100);
let vashu = new Student("Vashu", 15, 80);

if(manav.isAdult()){
    console.log("He is adult");
}
else{
    console.log("He is not adult");
}

manav.printDetails();
vashu.printDetails();

// console.log(manav);
// console.log(vashu);

console.log(manav.__proto__ == Student.prototype);
console.log(Student.prototype);