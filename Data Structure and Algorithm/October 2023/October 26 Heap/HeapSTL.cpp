#include<iostream>
#include<queue>
#include<functional>
using namespace std;
// priority queue == heap
class cmp{
    public:
    // Functor
    bool operator()(int a, int b){
        return a < b;
    }
};

int main(){
    // default
    // priority_queue<int> h; //only for maxheap

    // using class
    // priority_queue<int, vector<int>, cmp> h; //minheap(>), maxheap(<)

    // using functional header
    // priority_queue<int, vector<int>, greater<int>> h; //minheap
    priority_queue<int, vector<int>, less<int>> h; //maxheap
    
    h.push(9);
    h.push(2);
    h.push(1);
    h.push(0);
    h.push(3);
    h.push(5);

    while(!h.empty()){
        cout << h.top() << " ";
        h.pop();
    }
}