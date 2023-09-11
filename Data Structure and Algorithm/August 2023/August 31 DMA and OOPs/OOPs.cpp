#include<iostream>
#include<cstring>
using namespace std;
// Blueprint
class Car{
    public:

    // Datatypes
    char name[100];
    int price, model, seats;

    // Default Functions
    // 1 --> Constructors
    // 1.1 --> Default Constructors
    Car(){
        cout << "Hello, I am default constructor\n";
    }

    // 1.2 --> Parameterized Constructor
    Car(char* n, int p, int s, int m){
        cout << "Hello, I am parameterized constructor\n";
        strcpy(name, n);
        price = p;
        seats = s;
        model = m;
    }

    // 1.3 --> Copy Constructor
    // Car X = Y;
    // Car X(Y);
    Car(Car &Y){
        cout << "I am copy Constructor\n";
        strcpy(name, Y.name);
        price = Y.price;
        seats = Y.seats;
        model = Y.model;
    }

    // Functions
    void print(){
        cout << "Name : " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Model: " << model << endl;
        cout << "Seats: " << seats << endl;
    }
};

int main(){
    Car A; // A is a object of class Car, gets created using default constructor
    strcpy(A.name, "BMW"); // It is used to copy name in char array of class Car
    A.price = 100;
    A.model = 2020;
    A.seats = 4;
    A.print();

    // Both are same
    // char x[] = "Audi";
    // Car B(x, 200, 2022, 2);
    Car B("Audi", 200, 2022, 2); // Gets created using parameterized constructor
    strcpy(B.name, "Audi A8"); // Update name of Audi Car
    B.print();

    Car C = B; // Calling Copy Constructor
    C.print();
}