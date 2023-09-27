#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

// INSERTION IN LINKED LIST
void insertAtFront(node* &head, node* &tail, int data){
    if(head == NULL){ //Linked List is empty
        node* n = new node(data);
        head = tail = n;
    }
    else{
        // 1. Create a node
        node* n = new node(data);

        // 2. Connect the node at correct place
        n->next = head;

        // 3. Update head
        head = n;
    }
}

void insertAtMiddle(){}

void insertAtEnd(){}

// PRINTING LINKED LIST
void printLL(node* head){
    while(head != NULL){
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(){
    node* head, *tail;
    head = tail = NULL;
    
    insertAtFront(head, tail, 1);
    insertAtFront(head, tail, 2);
    insertAtFront(head, tail, 3);
    printLL(head);
}
