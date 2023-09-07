#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s;
    getline(cin, s);

    vector<string> temp;
    string str;

    for(char c : s){
        if(c == ' '){
            if(!str.empty()){
                temp.insert(temp.begin(), str);
                str = "";
            }
        }
		else{
            str += c;
        }
    }

    if(!str.empty()){
        temp.insert(temp.begin(), str);
    }

    for(int i = 0; i < temp.size(); ++i){
        cout << temp[i];
        
        if(i != temp.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
}
