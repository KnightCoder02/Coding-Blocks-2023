#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next; //Self referential class 
};

int main(){
    node a, b, c;

    a.data = 1;
    b.data = 2;
    c.data = 3;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    // Printing linkedlist
    // cout << a.data << " --> " << (*a.next).data << " --> NULL\n"; //Both are same
    cout << a.data << " --> " << a.next->data << " --> " << a.next -> next -> data << " --> NULL";
}