#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canCutWood(vector<int>& heights, int x, int sawHeight){
    long long woodCut = 0;
    
    for(int height : heights){
        if(height > sawHeight){
            woodCut += height - sawHeight;
        }
    }
    return woodCut >= x;
}

int findMaxSawHeight(vector<int>& heights, int x){
    int left = 0;
    int right = *max_element(heights.begin(), heights.end());

    int maxSawHeight = 0;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(canCutWood(heights, x, mid)){
            maxSawHeight = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return maxSawHeight;
}

int main(){
    int N;
    cin >> N;
    vector<int> heights(N);

    for(int i = 0; i < N; i++){
        cin >> heights[i];
    }

    int x;
    cin >> x;

    int maxSawHeight = findMaxSawHeight(heights, x);
    cout << maxSawHeight << endl;
}