#include<iostream>
#include<stack>
#include<vector>
using namespace std;

long long largestRectangleArea(vector<long long>& heights){
    stack<int> s;
    int n = heights.size();
    vector<long long> left(n), right(n);

    // Calculate the index of the next smaller bar on the left
    for(int i = 0; i < n; i++){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }

        left[i] = (s.empty() ? -1 : s.top());
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    // Calculate the index of the next smaller bar on the right
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }

        right[i] = (s.empty() ? n : s.top());
        s.push(i);
    }

    long long maxArea = 0;
    for(int i = 0; i < n; i++){
        long long width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }

    return maxArea;
}

int main(){
    int n;
    cin >> n;
    vector<long long> heights(n);

    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    long long result = largestRectangleArea(heights);
    cout << result << endl;
}