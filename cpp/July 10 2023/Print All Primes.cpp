#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        int flag = 1;
        for(int j = 2; j <= i - 1; j++){
            if(i % j == 0){
                flag = 0;
            }
        }

        if(flag == 1){
            // If flag is 1 then it is prime
            cout << i << " ";
        }
    }
}