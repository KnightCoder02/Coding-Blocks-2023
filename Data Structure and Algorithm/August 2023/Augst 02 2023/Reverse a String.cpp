#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char c[] = "Coding";
    int i = 0, j = strlen(c) - 1;
    while(i < j){
        swap(c[i], c[j]);
        i++;
        j--;
    }
    cout << c;
}