#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int arr[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
			if(j >= i){
                cout << arr[i][j];
            }
			else{
                cout << 0;
            }

            if(j < n - 1){
                cout << " ";
            }
        }

        cout << endl;
    }
}