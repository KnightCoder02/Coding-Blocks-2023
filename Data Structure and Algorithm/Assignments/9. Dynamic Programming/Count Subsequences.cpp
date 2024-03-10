#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

const int MOD = 1000000007;
int distinctSubsequences(string s){
    int n = s.length();
    
    // Initialize an array to store the count of distinct subsequences
    vector<int> dp(n + 1, 0);
    
    // Base case: empty string has one subsequence
    dp[0] = 1;
    
    // Map to store the last occurrence of a character
    unordered_map<char, int> lastOccurrence;
    
    // Iterate through the string
    for(int i = 1; i <= n; i++){
        // Current character
        char ch = s[i - 1];
        
        // Previous count of distinct subsequences
        dp[i] = (2 * dp[i - 1]) % MOD;
        
        // If current character has occurred before
        if(lastOccurrence.find(ch) != lastOccurrence.end()){
            // Subtract the count of subsequences ending with the previous occurrence of current character
            dp[i] = (dp[i] - dp[lastOccurrence[ch] - 1] + MOD) % MOD;
        }
        
        // Update the last occurrence of current character
        lastOccurrence[ch] = i;
    }
    return dp[n];
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        string s;
        cin >> s;
        
        // Output
        cout << distinctSubsequences(s) << endl;
    }
}