#include<iostream>
using namespace std;

int countTwins(const string &str, int index = 0){
    if(index >= str.length() - 2){
        return 0;
    }

    int count = 0;
    if(str[index] == str[index + 2]){
        count = 1;
    }

    return count + countTwins(str, index + 1);
}

int main(){
    string input;
    cin >> input;

    int result = countTwins(input);
    cout << result << endl;
}