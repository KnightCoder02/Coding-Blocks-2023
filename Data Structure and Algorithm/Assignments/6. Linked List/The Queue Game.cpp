#include <iostream>
#include <stack>
using namespace std;
int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        stack<int> st;
        bool valid = true;
        
        for(int i = 0; i < n; i++){
            int operation;
            cin >> operation;
            
            if(operation == 1){
                st.push(1);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    valid = false;
                }
            }
        }
        
        if(valid){
            cout << "Valid" << endl;
        }
        else{
            cout << "Invalid" << endl;
        }
    }
}