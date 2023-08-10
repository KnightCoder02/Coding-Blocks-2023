#include<iostream>
using namespace std;
int main(){
    int n, arr[50], target, i;
    cin >> n;

    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> target;

    for(i = 0; i < n; i++){
        if(arr[i] == target){
            continue;
        }
        cout << arr[i] << " ";
    }
}
