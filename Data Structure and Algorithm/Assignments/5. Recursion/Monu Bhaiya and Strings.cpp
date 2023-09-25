#include<iostream>
#include<stack>
#include<vector>
using namespace std;

string removeDuplicateLetters(string s){
    vector<int> lastOccurrence(26, -1);
    vector<bool> visited(26, false);

    for(int i = 0; i < s.length(); i++){
        lastOccurrence[s[i] - 'a'] = i;
    }

    stack<char> charStack;
    for(int i = 0; i < s.length(); i++){
        if(visited[s[i] - 'a']){
            continue;
        }

        while(!charStack.empty() && s[i] < charStack.top() && i < lastOccurrence[charStack.top() - 'a']){
            visited[charStack.top() - 'a'] = false;
            charStack.pop();
        }

        charStack.push(s[i]);
        visited[s[i] - 'a'] = true;
    }

    string result = "";
    while(!charStack.empty()){
        result = charStack.top() + result;
        charStack.pop();
    }
    return result;
}

int main(){
    string s;
    cin >> s;

    string result = removeDuplicateLetters(s);
    cout << result << endl;
}