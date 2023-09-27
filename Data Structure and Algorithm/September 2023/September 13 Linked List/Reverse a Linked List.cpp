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
void insertAtEnd(node* &head, node* &tail, int data){
    if(head == NULL){
        node* n = new node(data);
        head = tail = n;
    }
    else{
        node* n = new node(data);
        tail->next = n;
        tail = n;
    }
}

// REVERSE A LINKED LIST
void reverseLL(node* &head, node* &tail){
    node* c = head;
    node* p = NULL;
    node* n;

    while(c != NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    swap(head, tail);
}

// REVERSE A LINKED LIST - RECURSION
void reverseLLRecHelper(node* c, node* p = NULL){
    // Base case
    if(c == NULL){
        return;
    }
    
    // Recursive case
    node* n = c->next;
    c->next = p;
    reverseLLRecHelper(n, c); 
}

void reverseLLRec(node* &head, node* &tail){
    reverseLLRecHelper(head);
    swap(head, tail);
}

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
    
    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 6);    
    printLL(head);

    reverseLL(head, tail);
    printLL(head);

    reverseLLRec(head, tail);
    printLL(head);
}