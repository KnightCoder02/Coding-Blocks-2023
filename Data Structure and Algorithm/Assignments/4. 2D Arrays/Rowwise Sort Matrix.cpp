#include<iostream>
using namespace std;
void sortRowWise(int m[][100], int r, int c){
    for(int i = 0; i < r; i++){
	    for(int j = 0; j < c; j++){
	        for(int k = 0; k < c - j - 1; k++){
		        if(m[i][k] > m[i][k + 1]){
		            swap(m[i][k], m[i][k + 1]);
                }
	        }
	    }
    }

    for(int i = 0; i < r; i++){
	    for(int j = 0; j < c; j++){
	        cout << m[i][j] << " ";
        }
	cout << endl;
    }
}

int main(){
    int m[100][100] = {};
    int r, c;
    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }

    sortRowWise(m, r, c);
}