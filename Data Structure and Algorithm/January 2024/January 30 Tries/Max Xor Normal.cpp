#include<iostream>
using namespace std;
int main(){
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);
    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans, a[i] ^ a[j]);
        }
    }

    cout << ans << endl;
}