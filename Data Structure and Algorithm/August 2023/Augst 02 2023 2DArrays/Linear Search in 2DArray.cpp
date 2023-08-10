#include<iostream>
using namespace std;
int main(){
    int a[100][100];
    int n, m, row, col;
    cout << "Enter rows and cols: ";
    cin >> n >> m;
    int number = 1;

    for(row = 0; row < n; row++){
        for(col = 0; col < m; col++){
            // cin >> a[row][cols];
            a[row][col] = number;
            number++;
            cout << a[row][col] << " ";
        }
        cout << endl;
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    for(row = 0; row < n; row++){
        for(col = 0; col < m; col++){
            if(a[row][col] == key){
                cout << "Key Found at index: " << row << ", " << col;
                break;
            }
        }
        if(col < m){
            break;
        }
    }
    if(row == n){
        cout << "Key not found";
    }
}