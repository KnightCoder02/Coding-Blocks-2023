#include<iostream>
#include<cstring>
using namespace std;

long long int dp[5000][5000];
int subsetSum(int arr[], int n, int sum){
	if(sum == 0){
		return 1;
	}

	if(n < 0 || sum < 0){
		return 0;
	}
	 
	if(dp[n][sum] != -1){
		return dp[n][sum];
	}
	else{
		int include = subsetSum(arr, n - 1, sum - arr[n]);
		int exclude = subsetSum(arr, n - 1, sum);
        dp[n][sum] = include || exclude;
	}
	return dp[n][sum];
}

int main(){
    int n, sum;
	cin >> n >> sum;

	int arr[n];	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));
	if(subsetSum(arr, n - 1, sum)){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
}