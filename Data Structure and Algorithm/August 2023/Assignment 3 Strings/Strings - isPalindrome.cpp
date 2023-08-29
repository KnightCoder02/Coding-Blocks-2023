#include<iostream>
#include<cstring>
using namespace std;
bool isPalindrome(char *c){
    int i = 0, j = strlen(c) - 1;
    
    while(i <= j){
        if(c[i] != c[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    char c[1000];
    cin.getline(c, 100);
    
    bool ans = isPalindrome(c);
    if(ans == 1){
        cout << "true";
    }
    else{
        cout << "false";
    }
}