#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> arr(n);
        vector<int> result(n, -1);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] > arr[st.top()]){
                result[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        for(int i = 0; i < n; i++){
            cout << arr[i] << "," << result[i] << endl;
        }
    }
}