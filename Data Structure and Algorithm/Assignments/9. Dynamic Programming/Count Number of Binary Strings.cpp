#include<iostream>
using namespace std;

long long countBinaryStrings(int N){
    long long dp[N+1];
    long long dp2[N+1];

    // Base cases
    dp[1] = 1;
    dp2[1] = 1;

    for(int i = 2; i <= N; i++){
        dp[i] = dp[i-1] + dp2[i-1];
        dp2[i] = dp[i-1];
    }

    return dp[N] + dp2[N];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int N;
        cin >> N;
        cout << countBinaryStrings(N) << endl;
    }
}