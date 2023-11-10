#include<iostream>
#include<vector>
using namespace std;
class MaxHeap{
    void heapify(int index){
        int left = 2 * index;
        int right = (2 * index) + 1;
        int min = index;

        if(left < v.size() && v[left] > v[min]){
            min = left;
        }

        if(right < v.size() && v[right] > v[min]){
            min = right;
        }

        if(min != index){
            swap(v[min], v[index]);
            heapify(min);
        }
    }

    public:
    vector<int> v;
    
    MaxHeap(){
        v.push_back(-1); // Insert random value at index 0 because no data will insert on 0 index

    }

    // Insertion
    void push(int data){
        v.push_back(data);
        int index = v.size() - 1;
        int p = index / 2;

        while(p > 0 && v[p] < v[index]){
            swap(v[p], v[index]);
            index = p;
            p /= 2;
        }
    }

    // Seaching
    int top(){
        return v[1];
    }

    // Deletion
    void pop(){
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }

    bool empty(){
        return v.size() == 1;
    }
};

int main(){
    MaxHeap h;
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