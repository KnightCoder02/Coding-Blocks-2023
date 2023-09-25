#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of ways to split the array into two groups with equal sums
int countWaysToSplit(vector<int>& arr, int index, int sum1, int sum2){
    if(index == arr.size()){
        if(sum1 == sum2){
            return 1;
        }
        return 0;
    }

    int currentElement = arr[index];

    // Include the current element in the first group
    int waysWithCurrent = countWaysToSplit(arr, index + 1, sum1 + currentElement, sum2);

    // Include the current element in the second group
    int waysWithoutCurrent = countWaysToSplit(arr, index + 1, sum1, sum2 + currentElement);
    return waysWithCurrent + waysWithoutCurrent;
}

// Function to find and print the two groups with equal sums
void findGroups(vector<int>& arr, int index, int sum1, int sum2, vector<int>& group1, vector<int>& group2){
    if(index == arr.size()){
        if(sum1 == sum2){
            for(int num : group1){
                cout << num << " ";
            }

            cout << "and ";
            
            for(int num : group2){
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    int currentElement = arr[index];

    // Include the current element in the first group
    group1.push_back(currentElement);
    findGroups(arr, index + 1, sum1 + currentElement, sum2, group1, group2);
    group1.pop_back();

    // Include the current element in the second group
    group2.push_back(currentElement);
    findGroups(arr, index + 1, sum1, sum2 + currentElement, group1, group2);
    group2.pop_back();
}

int main(){
    int N;
    cin >> N;
    vector<int> arr(N);

    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }

    int totalWays = countWaysToSplit(arr, 0, 0, 0);

    vector<int> group1, group2;
    findGroups(arr, 0, 0, 0, group1, group2);
    cout << totalWays << endl;
}