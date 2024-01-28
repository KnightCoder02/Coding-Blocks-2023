// LIS --> Longest Increasing Subsequence
#include<iostream>
#include<vector>
using namespace std;
int LIS_len = 0;
vector<int> ans;

void LIS(int *a, int n, vector<int> &v, int lv = INT_MAX){
    // base case
    if(n == 0){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << "   ";
        }
        cout << endl;

        if(v.size() > LIS_len){
            LIS_len = v.size();
            ans = v;
        }
        return;
    }

    // recursive case
    // 1. include
    if(lv > a[n - 1]){
        v.push_back(a[n - 1]);
        LIS(a, n - 1, v, a[n - 1]);
        v.pop_back(); //Backtracing
    }

    // 2. exclude
    LIS(a, n - 1, v, lv);
}

void LIS2(int *a, int n){
    int dp[10000];
    for(int i = 0; i < 10000; i++){
        dp[i] = 1;
    }

    for(int j = 1; j < n; j++){
        for(int k = j - 1; k >= 0; k--){
            if(a[j] > a[k]){
                dp[j] = max(dp[j], dp[k] + 1);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dp[i] << "  ";
    }
    cout << endl;
}

int main(){
    int a[] = {10, 9, 3, 5, 4, 11, 7, 8};
    int n = sizeof(a) / sizeof(int);
    
    vector<int> v;
    LIS(a, n, v);

    cout << "LIS: " << LIS_len << endl;
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    cout << endl;

    LIS2(a, n);
}