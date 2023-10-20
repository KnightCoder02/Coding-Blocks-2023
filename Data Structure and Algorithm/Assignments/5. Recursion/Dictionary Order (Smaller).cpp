#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string temp;

void solve(string in, string out){
    // base case
    if(in.size() == 0){
        if(out < temp){
            cout << out << endl;
        }
        return;
    }

    // recursive case
    for(int i = 0; i < in.size(); i++){
        out.push_back(in[i]);
        solve(in.substr(0, i) + in.substr(i + 1), out);
        out.pop_back();
    }
}

int main(){
    string in, out = " ";
    cin >> in;
    temp = in;

    sort(in.begin(), in.end());
    solve(in, out);
}