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

// MIDDLE OF LINKED LIST
node* midLL(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

    node* ans = midLL(head);
    cout << "Middle: " << ans->data;
}