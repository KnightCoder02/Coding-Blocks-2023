#include<iostream>
#include<cstring>
using namespace std;
bool isPalindrome(const string &str, int start, int end){
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int countPalindromicSubstrings(const string &input){
    int count = 0;
    int n = input.length();

    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(isPalindrome(input, i, j)){
                count++;
            }
        }
    }
    return count;
}

int main(){
    string input;
    cin >> input;

    int palindromeCount = countPalindromicSubstrings(input);
    cout << palindromeCount << endl;
}