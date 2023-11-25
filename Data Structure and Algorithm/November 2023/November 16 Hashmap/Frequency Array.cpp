#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int freq[10000] = {0};
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }

    for(int i = 0; i < 10000; i++){
        if(freq[i]){
            cout << i << "  " << freq[i];
            cout << endl;
        }
    }
}