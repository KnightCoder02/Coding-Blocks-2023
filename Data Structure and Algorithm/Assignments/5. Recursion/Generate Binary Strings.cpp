#include<iostream>
#include<cstring>
using namespace std;

void generateBinaryStrings(string &s, int index){
    if(index == s.length()){
        cout << s << " ";
        return;
    }

    if(s[index] == '?'){
        s[index] = '0';
        
        generateBinaryStrings(s, index + 1);
        s[index] = '1';

        generateBinaryStrings(s, index + 1);
        s[index] = '?'; // Reset the character to '?' for backtracking
    }
    else{
        generateBinaryStrings(s, index + 1);
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        generateBinaryStrings(s, 0);
        cout << endl;
    }
}