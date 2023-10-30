#include<iostream>
#include<stack>
using namespace std;
bool areBracketsBalanced(string str) {
    stack<char> s;

    for(char bracket : str){
        if(bracket == '(' || bracket == '{' || bracket == '['){
            // If it's an opening bracket, push it onto the stack.
            s.push(bracket);
        }
        else{
            // If it's a closing bracket, check if it matches the top of the stack.
            if(s.empty()){
                // If the stack is empty, it's unbalanced.
                return false;
            }

            char top = s.top();
            s.pop();

            if( (bracket == ')' && top != '(') || 
                (bracket == '}' && top != '{') ||
                (bracket == ']' && top != '[') ){
                // If the brackets don't match, it's unbalanced.
                return false;
            }
        }
    }

    // If there are unmatched opening brackets left in the stack, it's unbalanced.
    return s.empty();
}

int main(){
    string str;
    cin >> str;

    if(areBracketsBalanced(str)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}