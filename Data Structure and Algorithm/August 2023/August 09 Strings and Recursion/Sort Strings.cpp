/*
Sort the strings in the following way:
1. Smaller length string should come first
2. If two strings have same length then they should be sorted in descending order
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool cmp(string &x, string &y){
    if(x.size() == y.size()){
        return x > y;
    }

    return x.size() < y.size(); //It compare string according to the length of string
}

int main(){
    string s[] = {
        "hello",
        "world",
        "axe",
        "uid",
        "cat",
        "dog",
        "play",
        "it"
    };

    int n = 8;
    sort(s, s + n, cmp);

    for(int i = 0; i < n; i++){
        cout << s[i] << endl;
    }
}