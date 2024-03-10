#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin >> n;

    map<int, int> m;
    for(int i = 0; i < n; i++){
        int no;
        cin >> no;
        m[no]++;
    }

    int ans, max=0;
    for(auto it : m){
        if(it.second > max){
            ans = it.first;
            max = it.second;
        }
    }
    cout << ans << endl;
}