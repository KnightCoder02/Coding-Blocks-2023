function Vehicle(company){

}

function Car(company, model){
    
}

Car.prototype = Object.create(Vehicle.prototype);

Car.prototype.constructor = Car;
Vehicle.prototype.constructor = Vehicle;

/*
    > Car.prototype.__proto__
    {}
    > Car.prototype.__proto__ == Vehicle.prototype
    true
    > Vehicle.__proto__
    f () {[native code]}
    > Vehicle.__proto__ == Function.prototype
    true
*/