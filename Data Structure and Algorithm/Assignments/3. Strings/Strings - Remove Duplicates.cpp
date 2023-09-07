#include<iostream>
#include<cstring>
using namespace std;
string removeConsecutiveDuplicates(const string &input){
    string result;
    char prevChar = '\0';

    for(char c : input){
        if(c != prevChar){
            result += c;
            prevChar = c;
        }
    }
    return result;
}

int main(){
    string input;
    cin >> input;

    string removedDuplicates = removeConsecutiveDuplicates(input);
    cout << removedDuplicates << endl;
}