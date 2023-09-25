#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

set<string> result;

// Function to generate all words in dictionary order
void generateWords(string str, string current){
    if(str.empty()){
        result.insert(current);
        return;
    }

    for(int i = 0; i < str.length(); i++){
        string remaining = str;
        string nextCurrent = current + str[i];
        remaining.erase(i, 1);
        generateWords(remaining, nextCurrent);
    }
}

int main(){
    string input;
    cin >> input;

    generateWords(input, "");

    for(const string& word : result){
        if(word < input){
            cout << word << endl;
        }
    }
}