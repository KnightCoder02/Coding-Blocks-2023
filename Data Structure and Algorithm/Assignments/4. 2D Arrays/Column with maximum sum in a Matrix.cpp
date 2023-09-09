#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int matrix[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    int maxSum = 0;
    int maxCol = 0;

    for(int j = 0; j < n; j++){
        int colSum = 0;
        
		for(int i = 0; i < n; i++){
            colSum += matrix[i][j];
        }

        if(colSum > maxSum){
            maxSum = colSum;
            maxCol = j;
        }
    }

    cout << maxCol + 1 << " " << maxSum << endl;
}