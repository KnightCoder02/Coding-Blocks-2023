#include<iostream>
#include<cstring>
using namespace std;
int strToint(char* a, int n){
    // base case
    if(n == 0){
        return 0;
    }

    // recursive case
    int ld = a[n - 1] - '0';
    return strToint(a, n - 1) * 10 + ld;
}

int main(){
    char a[] = "1234";
    cout << strToint(a, strlen(a)) << endl;
    cout << strToint(a, strlen(a)) * 10 + 5;
}