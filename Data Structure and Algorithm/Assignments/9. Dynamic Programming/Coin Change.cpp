#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> coins(M);
    for(int i = 0; i < M; i++){
        cin >> coins[i];
    }

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for(int i = 0; i <= M; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            dp[i][j] = dp[i - 1][j];
            
            if(j - coins[i - 1] >= 0){
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    cout << dp[M][N] << endl;
}