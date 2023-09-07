#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int pos = 1;
    int odd_sum = 0;
    int even_sum = 0;

    while(n > 0){
        int x = n % 10;
        n = n / 10;
        if(pos % 2 == 1){
            odd_sum += x;
        }
        else{
            even_sum += x;
        }
        pos++;
    }
    cout << odd_sum << endl;
    cout << even_sum << endl;
}
