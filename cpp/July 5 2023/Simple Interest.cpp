#include<iostream>
using namespace std;
int main(){
    int p, r, t;
    float si;

    cout << "Enter P, R and T: ";
    cin >> p >> r >> t;

    si = (p * r * t) / 100.00;
    cout << "Simple Interest: " << si;
}