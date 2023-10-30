#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> findNextGreaterElements(const vector<int>& arr){
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for(int i = 0; i < 2 * n; i++){
        int current = arr[i % n];
        
        while(!st.empty() && arr[st.top()] < current){
            result[st.top()] = current;
            st.pop();
        }

        if(i < n){
            st.push(i);
        }
    }

    return result;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> result = findNextGreaterElements(arr);
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
}