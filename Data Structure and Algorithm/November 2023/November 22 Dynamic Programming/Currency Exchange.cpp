#include<iostream>
using namespace std;
int minCoins(int amt, int deno[], int n, int *dp){
    // base case
    if(amt == 0){
        return dp[amt] = 0;
    }

    if(dp[amt] != -1){
        return dp[amt];
    }

    // recursive case
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        if(amt >= deno[i]){
            int smallAmt = amt - deno[i];
            int x = minCoins(smallAmt, deno, n, dp);
            
            if(x != INT_MAX){
                ans = min(ans, x + 1);
            }
        }
    }
    return ans;
}

int bottomUp(int amt, int *deno, int n){
    int dp[1000];
    dp[0] = 0;
    for(int i = 0; i < 1000; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;    
    for(int rupees = 1; rupees <= amt; rupees++){
        for(int i = 0; i < n; i++){
            if(rupees >= deno[i]){
                int smallRupee = rupees - deno[i];
                
                if(dp[smallRupee] != INT_MAX){
                    dp[rupees] = min(dp[rupees], dp[smallRupee] + 1);
                }
            }
        }
    }
    return dp[amt];
}

int main(){
    int deno[] = {1, 7, 10};
    int n = sizeof(deno) / sizeof(int);

    int dp[1000];
    for(int i = 0; i < 1000; i++){
        dp[i] = -1;
    }
    cout << minCoins(34, deno, n, dp) << endl;
    cout << bottomUp(34, deno, n);
}