#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void next_permutation(vector<int>& arr){
    int n = arr.size();
    int i = n - 2;
    
    while(i >= 0 && arr[i] >= arr[i+1]){
        i--;
    }
    
    if(i == -1){
        reverse(arr.begin(), arr.end());
        return;
    }
    
    int j = n - 1;
    while(arr[j] <= arr[i]){
        j--;
    }
    
    swap(arr[i], arr[j]);
    int left = i + 1;
    int right = n - 1;
    
    while(left < right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        next_permutation(arr);

        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}