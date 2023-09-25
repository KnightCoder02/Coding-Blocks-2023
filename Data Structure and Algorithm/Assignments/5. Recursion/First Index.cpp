#include <iostream>
#include <vector>
using namespace std;

class First{
    public:
    int firstOccurance(int ctr, int n, vector<int>& arr, int target){
        if(ctr == n){
            return -1;
        }

        if(arr[ctr] == target){
            return ctr;
        }
        else{
            return firstOccurance(ctr + 1, n, arr, target);
        }
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << First().firstOccurance(0, n, arr, target) << endl;
}