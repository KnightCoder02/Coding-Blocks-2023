#include<iostream>
using namespace std;
int binary(int* a, int s, int e, int key){
    // base case
    if(s > e){
        return -1;
    }

    // recursive case
    int m = (s + e) / 2;
    if(a[m] == key){
        return m;
    }
    else if(a[m] < key){
        return binary(a, m + 1, e, key);
    }
    else{
        return binary(a, s, m - 1, key);
    }
}

int main(){
    int a[] = {2, 4, 3, 5, 1};
    int n = sizeof(a) / sizeof(int);
    
    int key;
    cin >> key;
    cout << binary(a, 0, n - 1, key);
}