#include<iostream>
#include<map>
using namespace std;

typedef long long ll;
map<ll,ll> dp;

ll maxGold(ll n){
	if(n == 0){
		return 0;
	}
    
	if(dp.count(n) != 0){
		return dp[n];
	}
    
	return dp[n] = max(n, maxGold(n / 2) + maxGold(n / 3) + maxGold(n / 4));
}

int main(){
	ll n;
	cin >> n;
	
	ll ans = n;
	cout << maxGold(n);
}