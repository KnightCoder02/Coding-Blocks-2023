// LCS --> Longest Common Subsequence
#include<iostream>
#include<cstring>
using namespace std;
int lcs(string s1, int n, string s2, int m){
    // base case
    if(n == 0 || m == 0){
        return 0;
    }

    // recursive case
    if(s1[n -  1] == s2[m - 1]){
        return 1 + lcs(s1, n - 1, s2, m - 1);
    }
    else{
        return max(lcs(s1, n - 1, s2, m), lcs(s1, n, s2, m - 1));
    }
}

int topDown(string s1, int n, string s2, int m, int dp[][100]){
    // base case
    if(n == 0 || m == 0){
        return dp[n][m] = 0;
    }

    if(dp[n][m] != -1){
        return dp[n][m];
    }

    // recursive case
    if(s1[n -  1] == s2[m - 1]){
        return dp[n][m] = 1 + topDown(s1, n - 1, s2, m - 1, dp);
    }
    else{
        return dp[n][m] = max(topDown(s1, n - 1, s2, m, dp), topDown(s1, n, s2, m - 1, dp));
    }
}

int bottomUp(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    int dp[100][100] = {0};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << "   ";
        }
        cout << endl;
    }

    return dp[n][m];
}

void printLCS(string s1, int n, string s2, int m, int dp[][100], string ans){
    // base case
    if(n == 0 && m == 0){
        cout << ans << endl;
        return;
    }

    // recursive case
    if(s1[n - 1] == s2[m - 1]){
        printLCS(s1, n - 1, s2, m - 1, dp, s1[n - 1] + ans);
    }
    else{
        if(dp[n - 1][m] == dp[n][m]){
            printLCS(s1, n - 1, s2, m, dp, ans);
        }

        if(dp[n][m - 1] == dp[n][m]){
            printLCS(s1, n, s2, m - 1, dp, ans);
        }
    }
}

int main(){
    string s1 = "abcd";
    string s2 = "abc";

    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    cout << lcs(s1, s1.size(), s2, s2.size()) << endl;
    cout << topDown(s1, s1.size(), s2, s2.size(), dp) << endl;
    cout << bottomUp(s1, s2) << endl;
    printLCS(s1, s1.size(), s2, s2.size(), dp, "");
}