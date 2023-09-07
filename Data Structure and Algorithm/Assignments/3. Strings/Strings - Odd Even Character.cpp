#include<iostream>
#include<cstring>
using namespace std;
string replaceCharacters(const string &input) {
    string result = input;
    for(int i = 0; i < result.length(); ++i){
        if(i % 2 == 0){
            result[i] = result[i] + 1; 
        }
        else{
            result[i] = result[i] - 1; 
        }
    }
    return result;
}

int main(){
    string input;
    cin >> input;

    string replacedString = replaceCharacters(input);
    cout << replacedString << endl;
}