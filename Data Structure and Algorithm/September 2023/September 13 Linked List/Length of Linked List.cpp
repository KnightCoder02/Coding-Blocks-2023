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

// LENGTH OF LINKED LIST
int lengthLL(node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

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
    cout << "Length: " << lengthLL(head) << endl;
}