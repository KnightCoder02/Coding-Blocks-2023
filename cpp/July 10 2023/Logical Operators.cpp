#include<iostream>
using namespace std;
int main(){
    int a = 0, b = 1;
    
    // if (a++ && ++b){
    //     ++a;
    // }
    // else{
    //     ++b;
    // }

    // if(++a && ++b){
    //     ++a;
    // }
    // else{
    //     ++b;
    // }

    // if(a++ || ++b){
    //     ++a;
    // }
    // else{
    //     ++b;
    // }

    if(++a || ++b){
        ++a;
    }
    else{
        ++b;
    }

    cout << "a: " << a << endl << "b: " << b;
}