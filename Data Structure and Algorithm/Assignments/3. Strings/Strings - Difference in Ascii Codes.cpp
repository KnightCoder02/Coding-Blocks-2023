#include<iostream>
#include<cstring>
using namespace std;
string insertAsciiDifference(const string &input){
    string result;
    for(int i = 0; i < input.length(); ++i){
        result += input[i];
        if(i < input.length() - 1){
            int diff = input[i + 1] - input[i];
            result += to_string(diff);
        }
    }
    return result;
}

int main(){
    string input;
    cin >> input;

    string result = insertAsciiDifference(input);
    cout << result << endl;
}