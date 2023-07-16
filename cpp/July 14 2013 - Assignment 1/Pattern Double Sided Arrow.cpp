/*
_ _ _ _ _ _ 1
_ _ _ _ 2 1 _ 1 2
_ _ 3 2 1 _ _ _ 1 2 3
4 3 2 1 _ _ _ _ _ 1 2 3 4
_ _ 3 2 1 _ _ _ 1 2 3
_ _ _ _ 2 1 _ 1 2
_ _ _ _ _ _ 1
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    for(int row = 1; row <= (n + 1) / 2; row++){
        if(row == 1){
            // 1. Print n - 2*row + 1 times spaces
            for(int i = 0; i < n - 2*row + 1; i++){
                cout << "  ";
            }

            // 2. Print 1
            cout << 1;
        }

        else{
            // 1. Print n - 2*row + 1 times spaces
            for(int i = 0; i < n - 2*row + 1; i++){
                cout << "  ";
            }

            // 2. Print decrease numbers row times, start: row
            for(int i = row; i >= 1; i--){
                cout << i << " ";
            }

            // 3. Print 2*row - 3 times spaces
            for(int i = 0; i < 2*row - 3; i++){
                cout << "  ";
            }

            // 4. Print increase numbers row times, start: 1
            for(int i = 1; i <= row; i++){
                cout << i << " ";
            } 
        }
        cout << endl;
    }

    for(int row = (n + 1) / 2 - 1; row >= 1; row--){
        if(row == 1){
            // 1. Print n - 2*row + 1 times spaces
            for(int i = 0; i < n - 2*row + 1; i++){
                cout << "  ";
            }

            // 2. Print 1
            cout << 1;
        }

        else{
            // 1. Print n - 2*row + 1 times spaces
            for(int i = 0; i < n - 2*row + 1; i++){
                cout << "  ";
            }

            // 2. Print decrease numbers row times, start: row
            for(int i = row; i >= 1; i--){
                cout << i << " ";
            }

            // 3. Print 2*row - 3 times spaces
            for(int i = 0; i < 2*row - 3; i++){
                cout << "  ";
            }

            // 4. Print increase numbers row times, start: 1
            for(int i = 1; i <= row; i++){
                cout << i << " ";
            } 
        }
        cout << endl;
    }
}