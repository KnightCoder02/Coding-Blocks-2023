#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[] = {1, 2, 3, 4};
    int size_a = sizeof(a); //n*sizeof(int);
    int n = sizeof(a) / sizeof(int);
    
    cout << size_a << endl;
    cout << n << endl;

    int lar = INT_MIN;
    for(int i = 0; i < n; i++){
        if(lar < a[i]){
            lar = a[i];
        }
    }

    cout << lar;
}