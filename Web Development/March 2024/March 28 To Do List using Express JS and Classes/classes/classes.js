class Student{
    constructor(name, age){
        this.name = name;
        this.age = age;
    }

    printDetails(){
        console.log("Name: ", this.name, ", Age: ", this.age);
    }

    get StudentName(){
        return this.name;
    }

    set StudentName(name){
        this.name = name;
    }
}

let manav = new Student("Manav", 24);
let vashu = new Student("Vashu", 15);

manav.printDetails();
vashu.printDetails();

// Getters and Setters are functions but we can use them as properties.
manav.StudentName = "Manav Aggarwal";
console.log("Student name is: ", manav.StudentName)