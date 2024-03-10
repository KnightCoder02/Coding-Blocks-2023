#include<iostream>
using namespace std;

long long uglyNumber(long long n){
	long long dp[n + 1] = {0};
	int i2 = 0, i3 = 0, i5 = 0;
    long next_multiple_of_2 = 2;
    long next_multiple_of_3 = 3;
    long next_multiple_of_5 = 5;
    long next_ugly_no = 1;

    dp[0] = 1;
    for(int i = 1; i < n; i++){
        next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        dp[i] = next_ugly_no;
        
        if(next_multiple_of_2 == next_ugly_no){
            i2++;
            next_multiple_of_2 = dp[i2] * 2;
        }
        if(next_multiple_of_3 == next_ugly_no){
            i3++;
            next_multiple_of_3 = dp[i3] * 3;
        }
        if(next_multiple_of_5 == next_ugly_no){
            i5++;
            next_multiple_of_5 = dp[i5] * 5;
        }
    }
    return next_ugly_no;
}

int main(){
	long long t;
	cin >> t;
	
    while(t--){
	    long long n;
	    cin >> n;
	    cout << uglyNumber(n) << endl;
	}
}