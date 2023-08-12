#include<iostream>
using namespace std;
int main(){
    int n, count;
    cin >> n;

    while(n > 0){
        int rem = n % 2;
        count += rem;
        n /= 2;
    }
    cout << "Set Bits: " << count;
}