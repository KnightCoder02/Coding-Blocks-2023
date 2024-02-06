#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> v(4);
    v[0].push_back(1);
    v[0].push_back(2);

    v[1].push_back(3);
    v[1].push_back(4);
    v[1].push_back(5);
    v[1].push_back(6);

    v[2].push_back(7);
    v[2].push_back(8);
    v[2].push_back(9);

    v[3].push_back(10);

    for(int i = 0; i < 4; i++){
        for(auto el : v[i]){
            cout << " " << el << " ";
        }
        cout << endl;
    }
}