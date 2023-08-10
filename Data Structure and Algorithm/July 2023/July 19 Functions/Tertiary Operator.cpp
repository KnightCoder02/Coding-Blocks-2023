#include<iostream>
using namespace std;
int main(){
    int n = 2;
    (n % 2 == 0)? cout << "Even\n" : cout << "Odd\n";
    
    bool ans = (n % 2 == 0)? true : false;
    if(ans){
        cout << "This is Even";
    }
    else{
        cout << "This is Odd";
    }
}