#include<iostream>
using namespace std;
int main(){
    int min_fah, max_fah, step;
    cin >> min_fah >> max_fah >> step;

    for (int i = min_fah; i <= max_fah; i += step)
    {
        int cel = (5 / 9.0) * (i - 32);
        cout << i << " " << cel << endl;
    }
}