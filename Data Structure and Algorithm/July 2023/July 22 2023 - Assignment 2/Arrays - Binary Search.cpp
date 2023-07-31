#include<iostream>
using namespace std;
int binarySearch(int a[], int n, int key){
    int s = 0, e = n - 1;
    while(s <= e){
        int m = (s + e) / 2;
        if(a[m] == key){
            return m;
        }
        else if(key > a[m]){
            s = m + 1;
        }
        else{
            e = m - 1;
        }
    }
    // if s > e, key is not found
    return -1;
}

int main(){
    int a[1024], n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int key;
    cin >> key;
    cout << binarySearch(a, n, key);
}