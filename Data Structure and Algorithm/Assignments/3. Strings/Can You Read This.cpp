#include<iostream>
#include<cstring>
using namespace std;
void printWordsFromCamelCase(const string &input){
    string word;
    for(char c : input){
        if(isupper(c)){
            if(!word.empty()){
                cout << word << endl;
                word.clear();
            }
        }
        word += c;
    }

    if(!word.empty()){
        cout << word << endl;
    }
}

int main(){
    string input;
    cin >> input;

    printWordsFromCamelCase(input);
}