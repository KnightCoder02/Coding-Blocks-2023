#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int> &height){
    int n = height.size();
    int leftMax = 0, rightMax = 0;
    int l = 0, r = n - 1;
    int unitOfWater = 0;

    while(l < r){
        if(height[l] < height[r]){
            if(leftMax > height[l]){
                unitOfWater += leftMax - height[l]; 
            }
            leftMax = max(leftMax, height[l]);
            l++;
        }
        else{
            if(rightMax > height[r]){
                unitOfWater += rightMax - height[r];
            }
            rightMax = max(rightMax, height[r]);
            r--;
        }
    }
    return unitOfWater;
}

int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height);
}