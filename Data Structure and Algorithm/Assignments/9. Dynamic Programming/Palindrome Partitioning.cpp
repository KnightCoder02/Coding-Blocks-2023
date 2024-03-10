#include<iostream>
#include<vector>
using namespace std;

// Function to check if a substring is a palindrome
bool isPalindrome(const string& s, int start, int end){
    while(start < end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

// Function to calculate the minimum number of partitionings
int minPartitionings(const string& s){
    int n = s.length();
    
    // Initialize a boolean matrix to store whether each substring is a palindrome or not
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    
    // Initialize a vector to store the minimum number of partitionings
    vector<int> minPartitions(n, 0);
    
    // Fill the boolean matrix
    for(int len = 1; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            
            if(isPalindrome(s, i, j)){
                dp[i][j] = true;
            }
        }
    }
    
    // Calculate the minimum number of partitionings
    for(int i = 0; i < n; i++){
        if(dp[0][i]){
            minPartitions[i] = 0;
        } 
        
        else{
            minPartitions[i] = i; // Maximum partitionings if no palindrome is found
            
            for(int j = 0; j < i; j++){
                if(dp[j + 1][i]){
                    minPartitions[i] = min(minPartitions[i], minPartitions[j] + 1);
                }
            }
        }
    }
    
    return minPartitions[n - 1];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        cout << minPartitionings(s) << endl;
    }
}