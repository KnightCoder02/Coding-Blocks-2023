// Sum of Triplets = 0
#include<iostream>
using namespace std;
int main(){
    int a[] = {1, 0, 2, -1, -4, -1};
    int n = sizeof(a) / sizeof(int);

    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if(a[i] + a[j] + a[k] == 0){
                    cout << a[i] << ", " << a[j] << ", " << a[k] << endl;
                }
            }
        }
    }
}