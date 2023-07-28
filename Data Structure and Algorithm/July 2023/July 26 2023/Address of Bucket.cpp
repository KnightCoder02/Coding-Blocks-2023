#include<iostream>
using namespace std;
int main(){
    int a = 10;
    float f = 10.11;
    double d = 1.11;

    cout << "&a: " << &a << endl; 
    cout << "&f: " << &f << endl; 
    cout << "&d: " << &d << endl;

    int ar[] = {1, 2, 3, 4};
    cout << "ar: " << ar << endl;
    cout << "&ar[0]: " << &ar[0] << endl;
}