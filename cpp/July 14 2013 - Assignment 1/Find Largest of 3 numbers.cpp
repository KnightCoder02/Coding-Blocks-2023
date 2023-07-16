#include<iostream>
#include<climits>
using namespace std;
int main(){
    int lar = INT_MIN, i = 1;
    while(i <= 3){
        int no;
        cin >> no;

        if(no > lar){
            lar = no;
        }
        i++;
    }

    cout << lar;
}