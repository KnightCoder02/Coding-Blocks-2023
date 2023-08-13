#include<iostream>
using namespace std;
bool check7(int* a, int n, int i){
    // base case
    if(i == n){
        return false;
    }

    // recursive case
    if(a[i] == 7){
        return true;
    }
    return check7(a, n, i + 1);
}

int first7(int* a, int n, int i){
    if(i == n){
        return -1;
    }

    if(a[i] == 7){
        return i;
    }
    return first7(a, n, i + 1);
}

int last7(int* a, int n){ // n represents the number of elements not index
    if(n == 0){
        return -1;
    }

    if(a[n - 1] == 7){
        return n - 1;
    }
    return last7(a, n - 1);
}

void printAll7(int* a, int n, int i){
    // base case
    if(i == n){
        return;
    }

    // recursive case
    if(a[i] == 7){
        cout << i << " ";
    }
    printAll7(a, n, i + 1);
}

int main(){
    int a[] = {7, 2, 7, 4, 5, 7};
    int n = sizeof(a) / sizeof(int);
    
    cout << check7(a, n, 0) << endl;
    cout << first7(a, n, 0) << endl;
    cout << last7(a, n) << endl;
    printAll7(a, n, 0);
}