#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(string str, int index = 0, int result = 0){
    if(index == str.length()) {
        return result;
    }

    int digit = str[index] - '0';
    result = result * 10 + digit;
    return stringToInt(str, index + 1, result);
}

int main(){
    string str;
    cin >> str;

    int result = stringToInt(str);
    cout << result << endl;
}