#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nge(int *arr, int n){
    vector<int> nge(n);
    stack<int> s;

    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }

        if(s.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = s.top();
        }
        s.push(arr[i]);
    }
    return nge;
}

int main(){
    int arr[100];
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> res = nge(arr, n);
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
}