#include<iostream>
using namespace std;
int main(){
    int a = 10;
    cout << "&a: " << &a << endl; //Prints Address of a

    int *ap = &a;
    cout << "ap: " << ap << endl; //Prints Value of ap which is address of a

    // Dereference Operator(*)
    cout << "*(&a): " << *(&a) << endl; //Prints Value of a
    cout << "*ap: " << *ap << endl; //Prints Value of a

}