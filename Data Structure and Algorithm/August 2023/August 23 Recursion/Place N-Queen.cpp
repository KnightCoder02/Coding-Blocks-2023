#include<iostream>
using namespace std;
bool safe(int board[][100], int r, int c, int n){
    // 1. No queen in column
    for(int i = 0; i < r; i++){
        if(board[i][c] == 1){
            return false; // If already placed queen on same column then cannot placed queen on r, c
        }
    }

    // 2. No queen on upper left and upper right diagonal
    int copy_r = r, copy_c = c;
    
    // Check Upper right diagonal
    while(r >= 0 && c < n){
        if(board[r][c] == 1){
            return false;
        }
        r--;
        c++;
    }

    r = copy_r;
    c = copy_c;

    // Check Upper left diagonal
    while(r >= 0 && c >= 0){
        if(board[r][c] == 1){
            return false;
        }
        r--;
        c--;
    }

    // if safe, then place queen on r, c
    return true; 
}

bool nQueen(int board[][100], int r, int n){
    // Base Case
    if(r == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[i][j] == 1 ? cout << " Q " : cout << " _ ";
            }
            cout << endl;
        }
        return true;
    }

    // Recursive Case
    for(int c = 0; c < n; c++){
        if(safe(board, r, c, n)){
            board[r][c] = 1; // Queen placed on r, c
            bool ans = nQueen(board, r + 1, n);
            
            if(ans == true){
                return true;
            }
            board[r][c] = 0; // Backtracking
        }
    }

    return false; // Placing queens are not possible
}

int main(){
    int board[100][100] = {0};
    int n;
    cin >> n;

    nQueen(board, 0, n);
}