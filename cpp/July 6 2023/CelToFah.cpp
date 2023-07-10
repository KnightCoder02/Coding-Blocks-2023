#include<iostream>
using namespace std;
int main(){
    int init, fval, step, cel;
    cin >> init >> fval >> step;

    int fah = init;
    while(fah <= fval){
        cel = (5 / 9.0) * (fah - 32);
        cout << fah << " " << cel << endl;
        fah = fah + step;
    }
}