#include<iostream>
#include<vector>
using namespace std;
#define vvi(v, rows, cols, val) vector<vector<int>> tor(rows, vector<int> (cols, val));
int main(){
    vector<vector<int>> v(4, vector<int> (4));
    int no = 1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            v[i][j] = no++;
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << v[i][j] << "    ";
        }
        cout << endl;
    }

    cout << "---------------------------------------\n";
    vector<vector<int>> vec(4, vector<int> (4, 5));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << vec[i][j] << "    ";
        }
        cout << endl;
    }

    cout << "-------------------------------------------\n";
    int rows = 4, cols = 4, val = 10;
    vvi(tor, rows, cols, val);
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << tor[i][j] << "    ";
        }
        cout << endl;
    }    
}