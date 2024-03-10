#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, long long> memo;

long long countWays(int n){
    if(n <= 2){
        return n;
    }

    // Check if result is already computed
    if(memo.find(n) != memo.end()){
        return memo[n];
    }

    // Calculate the number of ways for current n
    long long ways = countWays(n - 1) + (n - 1) * countWays(n - 2);

    // Memoize the result
    memo[n] = ways;
    return ways;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << countWays(n) << endl;
    }
}