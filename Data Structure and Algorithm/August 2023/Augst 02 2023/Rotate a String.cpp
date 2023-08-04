#include<iostream>
#include<cstring>
using namespace std;
void rotate(char* c, int k){
    int len = strlen(c);

    // Shift k-times all characters ahead
    int i = len - 1;
    while(i >= 0){
        c[i + k] = c[i];
        i--;
    }

    // Shift k characters from last to first
    int j = len;
    i = 0;
    while(i < k){
        c[i] = c[j];
        i++;
        j++;
    }

    //Add null(\0) at len position
    c[len] = '\0';
}

int main(){
    char c[100] = "Coding";
    int k = 7;
    k %= strlen(c);
    rotate(c, k);
    cout << c;
}