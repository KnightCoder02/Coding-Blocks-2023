#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxBiotonicLength(vector<int>& arr){
    int n = arr.size();
    if(n == 0){
        return 0;
    }

    // Longest increasing subsequence ending at index i
    vector<int> lis(n, 1);

    // Longest decreasing subsequence starting from index i
    vector<int> lds(n, 1);

    // Compute longest increasing subsequence ending at each index
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    // Compute longest decreasing subsequence starting from each index
    for(int i = n - 2; i >= 0; --i){
        for(int j = n - 1; j > i; --j){
            if(arr[i] > arr[j]){
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    // Find the maximum length of biotonic subsequence
    int max_length = 0;
    for(int i = 0; i < n; i++){
        max_length = max(max_length, lis[i] + lds[i] - 1);
    }

    return max_length;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << maxBiotonicLength(arr) << endl;
    }
}