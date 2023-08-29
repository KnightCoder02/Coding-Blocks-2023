/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
This triangle is made by using nCr = (nCr-1) * (n - r + 1) / r
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int row = 0; row < n; row++){
        int pt = 1;
        cout << pt << " ";
        
        for (int j = 1; j <= row; ++j){
            int ct = pt * (row - j + 1) / j;
            cout << ct << " ";
            pt = ct;
        }
    cout << endl;
    }
}