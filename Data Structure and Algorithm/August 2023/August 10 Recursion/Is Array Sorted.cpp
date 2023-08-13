#include<iostream>
using namespace std;
bool isSorted(int* a, int n){
    //base case
    if(n == 0 || n == 1){
        return true;
    }

    //recursive case
    bool small = isSorted(a + 1, n - 1);
    if(a[0] <= a[1] && small == true){
        return true;
    }
    else{
        return false;
    }
}

bool isSorted2(int* a, int n){
    if(n <= 1){
        return n;
    }

    bool small = isSorted2(a, n - 1);
    if(a[n - 1] >= a[n - 2] && small == true){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int a[] = {1, 2, -3, 4, 5};
    int n = sizeof(a) / sizeof(int);
    cout << isSorted(a, n) << endl;
    cout << isSorted2(a, n);
}