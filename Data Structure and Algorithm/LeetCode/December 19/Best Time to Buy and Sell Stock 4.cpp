class Solution{
    public:
    int solve(int i, vector<int>& prices, int k, bool buy, int transactions, int dp[][301]){
        // base case
        if(i == prices.size() || k == 2*transactions){
            return dp[i][k] = 0;
        }

        if(dp[i][k] != -1){
            return dp[i][k];
        }

        // recursive case
        int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

        // buying
        if(!buy){
            op1 = -prices[i] + solve(i + 1, prices, k + 1, true, transactions, dp);
        }
        // selling
        else{
            op2 = +prices[i] + solve(i + 1, prices, k + 1, false, transactions, dp);
        }
        // waiting
        op3 = 0 + solve(i + 1, prices, k, buy, transactions, dp);
        return dp[i][k] = max(op1, max(op2, op3));
    }

    int maxProfit(int totalTransactions, vector<int>& prices){
        int transactions = totalTransactions;
        int dp[1004][301];
        memset(dp, -1, sizeof(dp));
        return solve(0, prices, 0, false, transactions, dp);
    }
};