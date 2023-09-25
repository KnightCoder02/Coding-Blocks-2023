#include<iostream>
#include<vector>
using namespace std;

class MyClass{
    public:
    int lastOccurrence(vector<int>& arr, int index, int target){
        if(index == -1){
            return -1;
        }

        if(arr[index] == target){
            return index;
        }
        else{
            return lastOccurrence(arr, index - 1, target);
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

    cout << MyClass().lastOccurrence(arr, n - 1, target) << endl;
}