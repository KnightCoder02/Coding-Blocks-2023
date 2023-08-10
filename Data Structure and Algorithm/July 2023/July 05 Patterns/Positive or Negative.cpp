#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    if(n == 0){
        cout << "You entered 0";
    }
    else if (n > 0){
        cout << "Positive number";
    }
    else{
        cout << "Negative number";
    }
}