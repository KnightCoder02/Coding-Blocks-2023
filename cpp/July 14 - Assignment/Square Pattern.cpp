/*
12345
22345
33345
44445
55555
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j > i){
                cout << j << " "; 
            }
            else{
                cout << i << " ";
            }
        }
        cout << endl;
    }
}