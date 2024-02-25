#include<iostream>
#include<set>
#include<functional> // For decreasing order
using namespace std;

int main(){
    set<int> s; //For Increasing
    set<int, greater<int>> s;   //For Decreasing
    // Insertion: O(log N)
    // Deletion: O(log N)
    // Set will not accept duplicate values

    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(4);

    // s.begin() --> It gives starting address of node
    auto f = s.begin();
    while(!s.empty()){
        cout << *f << endl;
        s.erase(f);
        f = s.begin();
    }
}