#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool cmp(string &x, string &y){
    cout << "Comparing: " << x << " and " << y << endl;
    return x < y;
}

int main(){
    string s[] = {
        "Hello",
        "World",
        "Eeco",
        "Coding",
        "Book"
    };

    int n = 5;
    sort(s, s + n, cmp); //It sort according to the dictionary
    
    for(int i = 0; i < n; i++){
        cout << s[i] << endl;
    }
}