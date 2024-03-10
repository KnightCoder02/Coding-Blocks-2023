#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices, int n){
    // Create a DP array to store the maximum profit for each rod length
    vector<int> dp(n + 1, 0);

    // Fill the DP table bottom-up
    for(int i = 1; i <= n; i++){
        int max_val = INT_MIN;
        
        for(int j = 0; j < i; j++){
            max_val = max(max_val, prices[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main(){
    int N;
    cin >> N;
    vector<int> prices(N);
    
    for(int i = 0; i < N; i++){
        cin >> prices[i];
    }

    int n;
    cin >> n;
    cout << maxProfit(prices, n) << endl;
}