#include<iostream>
using namespace std;
int main(){
    int r, c;
    cin >> r >> c;

// Creating 2D Array
    int** a = new int*[r];
    for(int i; i < r; i++){
        a[i] = new int[c];
    }

// Initializing value in 2D Array
    int number = 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            a[i][j] = number++;
        }
    }

// Printing 2D Array
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

// Deleting 2D Array
    for(int i = 0; i < r; i++){
            delete[] a[i];
    }

    delete[] a;
}