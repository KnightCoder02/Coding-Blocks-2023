#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxPiyushValue(vector<int>& coins){
    int n = coins.size();
    
    // Create a 2D DP array to store the maximum value Piyush can win with
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP table diagonally
    for(int i = 0; i < n; i++){
        dp[i][i] = coins[i];
    }

    for(int len = 2; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;
            dp[i][j] = max(coins[i] + min(x, y), coins[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    cout << maxPiyushValue(coins) << endl;
}