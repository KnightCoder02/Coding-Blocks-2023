#include<iostream>
#include<stack>
using namespace std;

class QueueWithTwoStacks{
    private:
    stack<int> stack1; // For enqueue.
    stack<int> stack2; // For dequeue.

    public:
    void enqueue(int x){
        stack1.push(x);
    }

    int dequeue(){
        if(stack2.empty()){
            // Transfer elements from stack1 to stack2 to reverse the order.
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if(stack2.empty()){
            // Queue is empty.
            return -1;
        }

        int front = stack2.top();
        stack2.pop();
        return front;
    }

    bool isEmpty(){
        return stack1.empty() && stack2.empty();
    }
};

int main(){
    int n;
    cin >> n;

    QueueWithTwoStacks q;

    for(int i = 0; i < n; i++){
        q.enqueue(i);
    }

    while(!q.isEmpty()){
        cout << q.dequeue() << " ";
    }
}