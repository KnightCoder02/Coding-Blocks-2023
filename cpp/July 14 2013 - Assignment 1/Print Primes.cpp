// Take N as input. Print all prime numbers from 2 to N.
#include<iostream>
using namespace std;
int main(){
    int no = 2, i = 2, flag = 1, n;
    cin >> n;

    while (no <= n){
        flag = 1;
        i = 2;

        while(i <= no - 1){
            if(no % i == 0){
                flag = 0;
            }
            i = i + 1;
        }

        if(flag == 1){
            cout << no << " ";
        }
        no = no + 1;
    }
}