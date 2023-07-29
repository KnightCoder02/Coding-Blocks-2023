#include<iostream>
#include<cstring>
using namespace std;
void copyString(char *a, char *b){
    int len = strlen(b);
    for(int i = 0; i <= len; i++){
        a[i] = b[i];
    }
}

int main(){
    char c[100], largest[100] = "";
    int n;
    
    cin >> n;
    cin.get();

    for(int i = 0; i < n; i++){
        cin.getline(c, 100);
        if(strlen(c) > strlen(largest)){
            copyString(largest, c);
        }
    }
    cout << largest;
}