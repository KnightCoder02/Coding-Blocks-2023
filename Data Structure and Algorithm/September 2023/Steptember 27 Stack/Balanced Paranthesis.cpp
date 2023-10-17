#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string x){
    stack<char> s;

    for(int i = 0; i < x.size(); i++){
        char ch = x[i];
        switch(ch){
            case '(' : case '{' : case '[' : 
                s.push(ch);             break;
            case '}' :
                if(!s.empty() && s.top() == '{'){
                    s.pop();
                }
                else{
                    return false;
                }                       break;
            case ')' :
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }
                else{
                    return false;
                }                       break;
            case ']' :
                if(!s.empty() && s.top() == '['){
                    s.pop();
                }
                else{
                    return false;
                }                       break;
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s = "[a+b*{c+(d-e)*f})]";

    if(isBalanced(s)){
        cout << "Balanced";
    }
    else{
        cout << "Not balanced";
    }
}