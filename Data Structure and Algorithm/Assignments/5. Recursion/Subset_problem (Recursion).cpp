#include <iostream>
using namespace std;

int count = 0;
void printSubsetSum(int *arr, int n, int i, int currentSum, int targetSum, string currentSubset) {
    if(i == n){
        if(currentSum == targetSum){
            cout << currentSubset << " ";
            count ++;
        }
        return;
    }

    // Include the current element in the subset.
    printSubsetSum(arr, n, i + 1, currentSum + arr[i], targetSum, currentSubset + ((currentSubset.size() > 0)? " " : "") + to_string(arr[i]));

    // Exclude the current element from the subset.
    printSubsetSum(arr, n, i + 1, currentSum, targetSum, currentSubset);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int targetSum;
    cin >> targetSum;

    printSubsetSum(arr, n, 0, 0, targetSum, "");
    cout << endl << count;
}
