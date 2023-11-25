#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int solve(vector<int> nums, int i, vector<int> &dp){
        // base case
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int take = 0;
        take = nums[i] + solve(nums, i + 2, dp);
        
        int notTake = solve(nums, i + 1, dp);
        return dp[i] = max(take,notTake);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);    
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    cout << rob(nums);
}