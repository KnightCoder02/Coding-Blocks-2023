#include<iostream>
#include<vector>
using namespace std;

int maxSubsetValue(vector<int>& wt, vector<int>& val, int cap){
    int n = wt.size();
    vector<int> dp(cap + 1, 0);

    for(int i = 1; i <= cap; i++){
        for(int j = 0; j < n; j++){
            if(wt[j] <= i){
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
            }
        }
    }

    return dp[cap];
}

int main(){
    int n, cap;
    cin >> n >> cap;

    vector<int> wt(n);
    vector<int> val(n);

    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }

    for(int i = 0; i < n; i++){
        cin >> val[i];
    }

    cout << maxSubsetValue(wt, val, cap) << endl;
}