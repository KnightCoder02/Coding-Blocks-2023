#include<iostream>
#include<vector>
using namespace std;

int count_combinations(vector<int>& coins, int amount){
    vector<int> dp(amount + 1);
    dp[0] = 1;

    for(int coin : coins){
        for(int i = coin; i <= amount; i++){
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

int main(){
    int amount, size;
    cin >> amount >> size;
    vector<int> coins(size);

    for(int i = 0; i < size; i++){
        cin >> coins[i];
    }

    cout << count_combinations(coins, amount) << endl;
}