#include<iostream>
#include<climits> //INT_MIN, INT_MAX
using namespace std;
int main(){
    // INT_MIN: -2147483648, INT_MAX = 2147483647;
    int lar = INT_MIN;
    int n, no, i = 1;

    cin >> n;
    
    while(i <= n){
        cin >> no;
        
        if(no > lar){
            lar = no;
        }
        
        i = i + 1;
    }

    cout << "Largest: " << lar << endl;
}