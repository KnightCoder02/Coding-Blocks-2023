#include<iostream>
using namespace std;

bool ratInMaze(char maze[][5], int i, int j, int n, int m, int sol[][10]){
    // base case
    if(i == n - 1 && j == m - 1){
        // Destination is also a part of sol
        sol[i][j] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        // return true; // Destination reached
        return false; // One path found but if we found all possible paths
    }

    // recursive case
    // Assume starting position as sol part
    sol[i][j] = 1;

    // 1. Go to right and check that maze can solve or not
    if(j + 1 < m && maze[i][j + 1] != 'X'){
        bool isRightTrue = ratInMaze(maze, i, j + 1, n, m, sol);
        if(isRightTrue == true){
            return true;
        }
    }

    // 2. Go to down and check that maze can solve or not
    if(i + 1 < n && maze[i + 1][j] != 'X'){
        bool isDownTrue = ratInMaze(maze, i + 1, j, n, m, sol);
        if(isDownTrue == true){
            return true;
        }
    }

    // Maze cannot solve from right or from down then
    sol[i][j] = 0;  // Bakctracking
    return false;
}

int main(){
    char maze[][5] = {
        "0000",
        "00XX",
        "0000",
        "XX00",
    };

    int sol[10][10] = {0};
    ratInMaze(maze, 0, 0, 4, 4, sol);
}