#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxCircularSum(vector<int> &nums, int n){
    int maxStraightSum = INT_MIN;
    int maxEndingHere = 0;

    for(int i = 0; i < n; i++){
        maxEndingHere = maxEndingHere + nums[i];
        
        if(maxEndingHere < 0){
            maxEndingHere = 0;
        }

        if(maxStraightSum < maxEndingHere){
            maxStraightSum = maxEndingHere;
        }
    }

    int maxCircularSum = 0;
    int arraySum = 0;

    for(int i = 0; i < n; i++){
        arraySum += nums[i];
        nums[i] = -nums[i];
    }

    int maxCircularEndingHere = nums[0];
    for(int i = 1; i < n; i++){
        maxCircularEndingHere = max(nums[i], maxCircularEndingHere + nums[i]);
        if(maxCircularEndingHere < 0){
            maxCircularEndingHere = 0;
        }

        if(maxCircularSum < maxCircularEndingHere){
            maxCircularSum = maxCircularEndingHere;
        }
    }

    if(maxCircularSum == 0){
        return maxStraightSum;
    }

    return max(maxStraightSum, arraySum + maxCircularSum);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int result = maxCircularSum(nums, n);
        cout << result << endl;
    }
}