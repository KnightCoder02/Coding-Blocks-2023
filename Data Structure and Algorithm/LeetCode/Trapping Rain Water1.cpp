#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int> &height){
    int n = height.size();
    vector<int> leftMax(n), rightMax(n);

    //Calculating the leftMax buildings for every given building
    leftMax[0] = 0;
    int leftMax_building = height[0];

    for(int i = 1; i < n; i++){
        leftMax[i] = leftMax_building;
        leftMax_building = max(leftMax_building, height[i]);
    }

    //Calculating the rightMax buildings for every given building
    rightMax[n - 1] = 0;
    int rightMax_building = height[n - 1];

    for(int i = n - 2; i >= 0; i--){
        rightMax[i] = rightMax_building;
        rightMax_building = max(rightMax_building, height[i]);
    }

    //Find minimum of leftMax and rightMax and find unitOfWater collected
    int unitOfWater = 0;
    for(int i = 0; i < n; i++){
        int leftWater = min(leftMax[i], rightMax[i]) - height[i];
        if(leftWater > 0){
            unitOfWater += leftWater;
        }
    }
    return unitOfWater;
}

int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height);
}