#include<iostream>
#include<stack>
using namespace std;
int main(){
    int q;
    cin >> q;

    stack<int> codeModules;
    for(int i = 0; i < q; i++){
        int queryType;
        cin >> queryType;

        if(queryType == 1){
            // Student Query
            if(!codeModules.empty()){
                int cost = codeModules.top();
                codeModules.pop();
                cout << cost << endl;
            }
            else{
                cout << "No Code" << endl;
            }
        }
        else{
            // Instructor Query
            int cost;
            cin >> cost;
            codeModules.push(cost);
        }
    }
}