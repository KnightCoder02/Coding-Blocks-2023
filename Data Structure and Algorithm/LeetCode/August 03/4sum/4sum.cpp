#include<iostream>
using namespace std;
int main(){
    int a[] = {1, 0, -1, 0, -2, 2};
    int n = sizeof(a) / sizeof(int);
    int target = 0;

    for(int i = 0; i < n - 3; i++){
        for(int l = i + 1; l < n - 2; l++){
            for(int j = l + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    if(a[i] + a[j] + a[k] + a[l] == target){
                        cout << a[i] << ", " << a[j] << ", " << a[k] << ", " << a[l] << endl;
                    }
                }
            }
        }
    }
}