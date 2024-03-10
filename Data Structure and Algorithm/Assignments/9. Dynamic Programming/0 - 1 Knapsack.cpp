#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int knapsack_problem(int si, int value[], int weight[], int n, int capacity, vector<vector<int>> &dp){
	if(si == n){
		return 0;
	}
	
	if(dp[si][capacity] != -1){
		return dp[si][capacity];
	}
	
	int include = INT_MIN, exclude = INT_MIN;
	exclude = knapsack_problem(si + 1, value, weight, n, capacity, dp);
	if(weight[si] <= capacity){
		include = value[si] + knapsack_problem(si + 1, value, weight, n, capacity - weight[si], dp);
	}
	
	int result = max(include,exclude);
	dp[si][capacity] = result;
	return result;
}

int main(){
	int n;
	cin >> n;
	
	int capacity;
	cin >> capacity;
	
	int weight[1005];
	int value[1005];
	
	for(int i = 0; i < n; i++){
		cin >> weight[i];
	}

	for(int i = 0; i < n; i++){
		cin >> value[i];
	}

    int col = capacity + 1;
    int row = n + 1;
	
	vector<vector<int>> dp(row, vector<int>(col, -1));
	cout << knapsack_problem(0, value, weight, n, capacity, dp);
	cout << endl;
}