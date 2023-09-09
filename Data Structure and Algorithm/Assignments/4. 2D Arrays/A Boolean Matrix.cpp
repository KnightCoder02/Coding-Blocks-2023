#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    
    vector<int> rowToUpdate(m, 0);
    vector<int> colToUpdate(n, 0);
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 1){
                rowToUpdate[i] = 1;
                colToUpdate[j] = 1;
            }
        }
    }

    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(rowToUpdate[i] == 1 || colToUpdate[j] == 1){
                mat[i][j] = 1;
            }
        }
    }

    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}