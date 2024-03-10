#include<iostream>
using namespace std;

int min_jumps(int nums[], int n){
	int dp[n] = {0};
         
    if(n < 2){
        return 0;
    } 
    
    int max_reachable(nums[0]), limit(nums[0]);
    int count(1);
    for(int i = 1 ; i < n ; i++){
        if(i > limit){
            count += 1;
            limit = max_reachable;
        }
        
        max_reachable = max(max_reachable, nums[i] + i);
    }
    return count;
}

int main(){
	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		int a[n];

		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
	    cout << min_jumps(a, n) << "\n";
	}
}