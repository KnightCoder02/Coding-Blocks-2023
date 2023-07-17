// Continue is used to end the iteration and start loop again from starting position
#include<iostream>
using namespace std;
int main(){
    int n, i = 1;
    cin >> n;

    while(i <= n){
        cout << i << " ";
        if(i == 5){
            i++;
            continue;
        }
        i++;
    }
}