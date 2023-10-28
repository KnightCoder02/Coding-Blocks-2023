#include<iostream>
#include<stack>
using namespace std;
int main(){
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(int);
    int ns[1000], ps[1000];

    // Finding Next Smaller
    stack<int> s;
    s.push(0);
    for(int i = 1; i < n; i++){
        int ch = heights[i];
        while(!s.empty() && ch < heights[s.top()]){
            ns[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        ns[s.top()] = n;
        s.pop();
    }

    for(int i = 0; i < n; i++){
        cout << ns[i] << " ";
    }
    cout << endl;

    // Finding Previous Smaller
    s.push(n - 1);
    for(int i = n - 2; i >= 0; i--){
        int ch = heights[i];
        while(!s.empty() && ch < heights[s.top()]){
            ps[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        ps[s.top()] = -1;
        s.pop();
    }

    for(int i = 0; i < n; i++){
        cout << ps[i] << " ";
    }

    // Calculating area of rectangle 
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = ns[i] - ps[i] - 1;
        int b = heights[i];
        ans = max(ans, l * b);
    }

    cout << "\nArea: " << ans;
}