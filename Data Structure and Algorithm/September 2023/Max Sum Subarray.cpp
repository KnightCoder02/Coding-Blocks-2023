#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[] = {1, -5, 2, 4, -3, 10, -20};
    int n = sizeof(a) / sizeof(int);

    int maxSum = INT_MIN;
    // TC: 0(N^3)
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int ans = 0;
            for(int k = i; k <= j; k++){
                // cout << a[k] << " ";
                ans += a[k];
            }

            // cout <<", Sum: " << ans << endl;
            maxSum = max(maxSum, ans);
        }
    }

    cout << "Max sum: " << maxSum << endl;
}