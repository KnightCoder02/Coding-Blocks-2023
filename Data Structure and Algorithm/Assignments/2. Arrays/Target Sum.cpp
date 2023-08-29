#include<iostream>
using namespace std;
int main(){
    int a[30];
    int n, target;
    cin >> n >> target;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < (1 << n); i++){
        int num = i, sum = 0;

        for(int i = 0; i < n; i++){
            if((num & 1) == 0){
                // ith element of array will be positive
                sum += a[i];
            }
            else{
                // ith element of array will be negative
                sum -= a[i];
            }
            num = num >> 1;
        }

        if(sum == target){
            ans++;
        }
    }
    cout << ans;
}