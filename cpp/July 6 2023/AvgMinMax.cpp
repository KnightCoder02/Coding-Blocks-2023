#include<iostream>
#include<climits>
using namespace std;
int main(){
    int lar = INT_MIN, small = INT_MAX;
    int n, i = 1, no, sum = 0;
    cin >> n;

    while(i <= n){
        cin >> no;

        if(no > lar){
            lar = no;
        }

        if(no < small){
            small = no;
        }

        sum = sum + no;
        i = i + 1;
    }
    cout << "Largest: " << lar << endl;
    cout << "Smallest: " << small << endl;
    cout << "Average: " << sum / (n * 1.0) << endl;
    
}