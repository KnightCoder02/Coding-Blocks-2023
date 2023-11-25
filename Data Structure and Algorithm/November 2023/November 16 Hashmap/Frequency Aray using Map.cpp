#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int, int> mp;
    int n;
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    for(auto x : mp){
        cout << x.first << "  " << x.second;
    }
}