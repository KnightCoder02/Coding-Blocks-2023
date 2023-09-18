#include<iostream>
#include<cstring>
using namespace std;
class Car{
    private:
        int price;
    
    public:
    // Static Data Members
        static int count;
        char* name;
        int model, seats;

        // Constant Data members -> We can only initialize constant bucket, we did not assign value to constant bucket
        const int tyres; 

    Car() : tyres(4){
        cout << "Hello, I am default constructor\n";
        name = NULL;
        count++;
    }

    // If comment out then this process is called deep copy otherwise it called shallow copy
    Car(Car &Y) : tyres(4){
        cout << "I am copy Constructor\n";
        name = new char[strlen(Y.name) + 1];
        strcpy(name, Y.name);
        price = Y.price;
        seats = Y.seats;
        model = Y.model;
        count++;
    }

    Car(char* n, int p, int s, int m) : tyres(4), price(p), model(m), seats(s){
        cout << "Hello, I am parameterized constructor\n";
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        // price = p;
        // seats = s;
        // model = m;
        count++;
    }

    void operator = (Car Y){
        cout << "I am copy assignment operator\n";
        if(name != NULL){
            delete[] name;
        }
        name = new char[strlen(Y.name) + 1];
        strcpy(name, Y.name);
        price = Y.price;
        seats = Y.seats;
        model = Y.model;
    }

    ~Car(){
        count--;
    }

    void setName(char* n){
        if(name != NULL){
            delete[] name;
        }
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void setPrice(int p){
        if(p > 100 && p < 150){
            price = p;
        }
        else{
            price = 120;
        }
    }

    int getPrice(){
        return price;
    }

    void print(){
        cout << "Name : " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Model: " << model << endl;
        cout << "Tyres: " << tyres << endl;
        cout << "Seats: " << seats << endl;
    }

    // Operator Overloading
    bool operator > (Car &Y){
        if(price > Y.price){
            return true;
        }
        else{
            return false;
        }
    }
};

int Car :: count = 0; //Initialization of static members

int main(){
    Car A;
    A.setName("BMW");
    A.setPrice(100);
    A.model = 2020;
    A.seats = 4;

    Car B;
    B.setName("Audi");
    B.setPrice(233);
    B.model = 2022;
    B.seats = 2;

    Car C = A;
    Car D = A;

    D.name[0] = 'T';

    // Operator Overloading
    if(A > B){ //A called '>' this and B goes to argument
        cout << "A is costly\n";
    }
    else{
        cout << "B is costly\n";
    }

    A.print();
    B.print();
    C.print();
    D.print();

    cout << "Total number of cars: " << A.count << endl;
    cout << "Total number of cars: " << Car::count << endl;
}