#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1000000007;

int countWays(int n, int m){
    // Create a vector to store the number of ways to tile each row
    vector<int> dp(n + 1, 0);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Fill the dp table
    for(int i = 2; i <= n; i++){
        if(i < m){
            dp[i] = 1;
        }
        else if(i == m){
            dp[i] = 2;
        }
        else{
            dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
        }
    }

    return dp[n];
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n, m;
        cin >> n >> m;
        cout << countWays(n, m) << endl;
    }
}