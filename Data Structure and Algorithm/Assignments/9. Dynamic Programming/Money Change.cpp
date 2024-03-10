#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1000000007;
int coinChangeWays(vector<int>& denominations, int N){
    int m = denominations.size();
    
    // Create a DP table to store the number of ways to make change for amounts from 0 to N
    vector<int> dp(N + 1, 0);
    
    // Base case: There is one way to make change for amount 0 (by using no coins)
    dp[0] = 1;
    
    // Iterate through each denomination
    for(int i = 0; i < m; i++){
        // Update the DP table for each amount from denominations[i] to N
        for(int j = denominations[i]; j <= N; j++) {
            // Update the number of ways to make change for amount j
            dp[j] = (dp[j] + dp[j - denominations[i]]) % MOD;
        }
    }
    
    // Return the number of ways to make change for amount N
    return dp[N];
}

int main() {
    int T;
    cin >> T;

    while(T--){
        int M;
        cin >> M;

        vector<int> denominations(M);
        for(int i = 0; i < M; i++){
            cin >> denominations[i];
        }

        int N;
        cin >> N;

        cout << coinChangeWays(denominations, N) << endl;
    }
}