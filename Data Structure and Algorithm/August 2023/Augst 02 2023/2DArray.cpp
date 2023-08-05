#include<iostream>
using namespace std;
int main(){
    int a[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7},
        {9, 10, 11, 12}
    };

    int n = 3, m = 4;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cout << a[row][col] << " ";
        }
        cout << endl;
    }
}