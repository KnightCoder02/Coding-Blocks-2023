#include<iostream>
using namespace std;
int main(){
    int a;
    cin >> a;

    if(a > 10 && a < 20){
        cout << "A is between 10 and 20";
    }
    else if(a > 20 && a < 30){
        cout << "A is between 20 and 30";
    }
    else{
        cout << "Welcome to CB";
    }

    // if(a > 1){
    //     cout << "A is greater than 1";
    // }

    // else{
    //     cout << "A is not greater than 1";
    // }
}