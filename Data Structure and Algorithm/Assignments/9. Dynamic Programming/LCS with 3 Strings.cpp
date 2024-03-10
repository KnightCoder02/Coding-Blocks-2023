#include<iostream>
#include<cstring>
using namespace std;

int lcs3(char x[], char y[], char z[]){
    int n, m, p;
    
    n = strlen(x);
    m = strlen(y);
    p = strlen(z);

    int dp[n + 1][m + 1][p + 1];
    memset(dp,0,sizeof(dp));
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= p; k++){
                if(x[i - 1] == y[j - 1] && x[i - 1] == z[k - 1]){
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
			        ans = max(ans, dp[i][j][k]);
                }  
                else{
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    return ans;
}

int main(){
    char str1[205], str2[205], str3[205];
    cin >> str1 >> str2 >> str3;

    int ans = lcs3(str1, str2, str3);
    cout << ans;
}