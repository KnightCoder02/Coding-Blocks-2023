#include<iostream>
#include<vector>
using namespace std;

#define ll long long int
#define s(x) scanf("%lld",&x)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)

int main(){
  ll t = 1;
  s(t);

  while(t--){
    ll n;
    s(n);
    
    vector<ll> ar[n];
    F(i, 0, n - 1){
      ar[i] = vector<ll>(3, 0);
      F(j, 0, 2){
        cin >> ar[i][j];
      }
    }
        
    ll dp[n][3] = {0};
    dp[0][0] = ar[0][0];
    dp[0][1] = ar[0][1];
    dp[0][2] = ar[0][2];
      
    F(i, 1, n - 1){
      dp[i][0] = ar[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = ar[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = ar[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
      
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;
  }
}