#include<iostream>
#include<queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        priority_queue<int> leftheap;
        priority_queue<int, vector<int>, greater<int>> rightheap;
        
        int d;
        cin >> d;
        
        leftheap.push(d);
        int med = d;
        cout << med << " ";
    
        for(int i = 1; i < n; i++){ 
            cin >> d;
     
            if(leftheap.size() > rightheap.size()){
                if(d < med){
                    rightheap.push(leftheap.top());
                    leftheap.pop();
                    leftheap.push(d);
                }
                else{
                    rightheap.push(d);
                }
                med = (leftheap.top() + rightheap.top()) / 2;
            }
            else if(leftheap.size() == rightheap.size()){
                if(d < med){
                    leftheap.push(d);
                    med = leftheap.top();
                }
                else{
                    rightheap.push(d);
                    med = rightheap.top();
                }
            }
            else{
                if(d > med){
                    leftheap.push(rightheap.top());
                    rightheap.pop();
                    rightheap.push(d);
                }
                else{
                    leftheap.push(d);
                }
                med = (leftheap.top() + rightheap.top()) / 2;
            }

            cout << med << " ";
        }
        cout << endl;
    }
}