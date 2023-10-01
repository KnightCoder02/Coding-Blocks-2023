#include<iostream>
#include<cstring>
using namespace std;

void solve(string s, int i, string op){
    // Base case
    if(s[i] == '\0'){
        cout << op << " ";
        return;
    }

    // Recursive case
    if(s[i] == '?'){    
        solve(s, i + 1, op + "0");
    }

    if(s[i] == '?'){
        solve(s, i + 1, op + "1");
    }    

    else{
        solve(s, i + 1, op + s[i]);
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        solve(s, 0, "");
    }
}
