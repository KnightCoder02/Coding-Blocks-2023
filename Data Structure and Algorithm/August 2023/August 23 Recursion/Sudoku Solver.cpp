#include<iostream>
#include<cmath>
using namespace std;
bool safe(int a[][9], int i, int j, int no, int n){
    // 1. If Number is present in row and col
    for(int k = 0; k < n; k++){
        if(a[k][j] == no || a[i][k] == no){
            return false;
        }
    }

    // 2. If Number is present in 3*3 matrix
    n = sqrt(n); // Square root of n
    int si = (i / n) * n;
    int sj = (j / n) * n;
    for(int r = si; r < si + n; r++){
        for(int c = sj; c < sj + n; c++){
            if(a[r][c] == no){
                return false;
            }
        }
    }

    // 3. If both conditions are true then number is safe
    return true;
}

bool sudoku(int a[][9], int i, int j, int n){
    // Base Case
    if(i == n){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                cout << a[r][c] << " ";
            }
            cout << endl;
        }

        return true;
    }

    // Check 2 task before recursion
    // 1. If j == n then go to next row and col --> 0 
    if(j == n){
        bool remainingSolve = sudoku(a, i + 1, 0, n);
        return remainingSolve;
    }

    // 2. If cell is not empty then no need to fill
    if(a[i][j] != 0){
        bool remainingSolve = sudoku(a, i, j + 1, n);
        return remainingSolve;
    }

    // If both tasks are fine then fill empty cell
    // Recursive Case
    // Fill 1 - n number in an empty cell
    for(int no = 1; no <= n; no++){
        // Check placing of current number is safe or not
        if(safe(a, i, j, no, n) == true){
            a[i][j] = no;
            bool isSolve = sudoku(a, i, j + 1, n);
            if(isSolve == true){
                return true;
            }
            a[i][j] = 0; //Backtracking
        }
    }
    // If any 1-n number cannot place at i, j then exits from loop
    return false; //Not possible to fill current empty cell 
}

int main(){
    int mat[9][9] = 
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    sudoku(mat, 0, 0, 9);
}