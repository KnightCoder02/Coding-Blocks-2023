#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == n/2+1 || j == n/2+1 ||
			(i == 1 && j >= (n/2+1) && (j <= n)) ||
			(j == 1 && i <= (n/2+1)) ||
			(i == n && j <= (n/2+1)) ||
			(j == n && i >= (n/2+1) && (i <= n))){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}