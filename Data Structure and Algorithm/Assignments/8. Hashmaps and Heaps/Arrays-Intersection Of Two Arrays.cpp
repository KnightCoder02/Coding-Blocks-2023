#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findIntersection(int arr1[], int arr2[], int n){
    // Map to store the frequency of elements in the first array
    unordered_map<int, int> freq;

    // Vector to store the intersection elements
    vector<int> intersection;

    // Count the frequency of elements in the first array
    for(int i = 0; i < n; i++){
        freq[arr1[i]]++;
    }

    // Iterate through the second array and check if the element exists in the first array
    // If it exists, decrement its frequency in the map and add it to the intersection vector
    for(int i = 0; i < n; i++){
        if(freq[arr2[i]] > 0){
            intersection.push_back(arr2[i]);
            freq[arr2[i]]--;
        }
    }
    return intersection;
}

int main(){
    int n;
    cin >> n;

    int arr1[n], arr2[n];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }

    // Find the intersection of the two arrays
    vector<int> result = findIntersection(arr1, arr2, n);

    // Sort the result vector
    sort(result.begin(), result.end());

    // Print the intersection elements in the required format
    cout << "[";
    for(int i = 0; i < result.size(); i++){
        if(i > 0){
            cout << ", ";
        }

        cout << result[i];
    }

    cout << "]" << endl;
}