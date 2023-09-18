#include<iostream>
#include<cstring>
using namespace std;
// Blueprint
class Car{
    private:
        int price;
    
    public:
        char* name;
        int model, seats;

    Car(){
        cout << "Hello, I am default constructor\n";
        name = NULL;
    }

    Car(char* n, int p, int s, int m){
        cout << "Hello, I am parameterized constructor\n";
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        price = p;
        seats = s;
        model = m;
    }

    Car(Car &Y){
        cout << "I am copy Constructor\n";
        name = new char[strlen(Y.name) + 1];
        strcpy(name, Y.name);
        price = Y.price;
        seats = Y.seats;
        model = Y.model;
    }

    // Copy Assignment Operator 
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

    void setName(char* n){
        if(name != NULL){
            delete[] name;
        }
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Destructor
    ~Car(){
        cout << "Deleting " << name << endl;
    }

    // Setter and Getter
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
        cout << "Seats: " << seats << endl;
    }
};

int main(){
    Car A;
    // strcpy(A.name, "BMW");
    A.setName("BMW");

    // A.price = 100; // It is used when price is public
    A.setPrice(100); // It is used when price is private
    A.model = 2020;
    A.seats = 4;

    cout << A.getPrice() << endl;    
    A.print();

    Car B("Audi", 200, 2022, 2);
    strcpy(B.name, "Audi A8");
    B.print();

    Car C = B;
    C.print();

    B = A;  // Calling copy assignment operator
    B.print();
}