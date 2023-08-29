#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n, largest = INT_MIN;
    cin >> n;

    int* a = new int[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > largest){
            largest = a[i];
        }
    }

    cout << largest;
    delete[] a;
}