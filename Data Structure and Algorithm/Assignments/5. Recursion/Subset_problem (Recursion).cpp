#include<iostream>
#include<vector>
using namespace std;

// Function to print a vector
void printVector(const vector<int>& subset){
    for(int i = 0; i < subset.size(); i++){
        cout << subset[i] << " ";
    }
    cout << endl;
}

// Part a: Recursive function to find subsets that sum to the target and print them
void findSubsetsWithSum(vector<int>& arr, int index, int target, vector<int>& subset){
    if(target == 0){
        printVector(subset);
        return;
    }

    if(index == arr.size() || target < 0){
        return;
    }

    // Include the current element in the subset
    subset.push_back(arr[index]);
    findSubsetsWithSum(arr, index + 1, target - arr[index], subset);

    // Exclude the current element from the subset
    subset.pop_back();
    findSubsetsWithSum(arr, index + 1, target, subset);
}

// Part b: Recursive function to count subsets that sum to the target
int countSubsetsWithSum(vector<int>& arr, int index, int target){
    if(target == 0){
        return 1;
    }

    if(index == arr.size() || target < 0){
        return 0;
    }

    // Include the current element in the subset
    int includeCount = countSubsetsWithSum(arr, index + 1, target - arr[index]);

    // Exclude the current element from the subset
    int excludeCount = countSubsetsWithSum(arr, index + 1, target);

    return includeCount + excludeCount;
}

int main(){
    int N;
    cin >> N;
    vector<int> arr(N);

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    vector<int> subset;
    findSubsetsWithSum(arr, 0, target, subset);

    int count = countSubsetsWithSum(arr, 0, target);
    cout << count << endl;
}