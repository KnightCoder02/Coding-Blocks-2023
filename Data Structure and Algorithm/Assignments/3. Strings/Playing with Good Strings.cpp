#include<iostream>
#include<cstring>
using namespace std;
bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int longestGoodSubstring(const string &input){
    int maxLength = 0;
    int currentLength = 0;

    for(char c : input){
        if(isVowel(c)){
            currentLength++;
            maxLength = max(maxLength, currentLength);
        }
        else{
            currentLength = 0;
        }
    }
    return maxLength;
}

int main(){
    string input;
    cin >> input;

    int longestLength = longestGoodSubstring(input);
    cout << longestLength << endl;
}