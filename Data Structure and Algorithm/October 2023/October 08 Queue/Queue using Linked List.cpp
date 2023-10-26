#include<iostream>
using namespace std;

template<typename N>
class node{
    public:
    N data;
    node<N>* next;

    node(N d){
        data = d;
        next = NULL;
    }
};

template<typename T>
class Queue{
    node<T>* head;
    node<T>*tail;
    int cs;

    public:
    Queue(){
        head = tail = NULL;
        cs = 0;
    }

    void push(T data){
        cs++;
        if(!head){
            head = tail = new node<T>(data);
        }
        else{
            node<T>* n = new node<T>(data);
            tail->next = n;
            tail = n;
        }
    }

    void pop(){
        if(!head){
            return;
        }
        else if(!head->next){
            delete head;
            head = tail = NULL;
            cs--;
        }
        else{
            node<T>* temp = head;
            head = head->next;
            delete temp;
            cs--;
        }
    }

    bool empty(){
        return head == NULL;
    }

    int size(){
        return cs;
    }
    
    T front(){
        return head->data;
    }
};

int main(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}