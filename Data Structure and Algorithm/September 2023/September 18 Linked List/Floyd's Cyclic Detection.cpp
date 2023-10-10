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

// CYCLIC DETECTION
void breakCycle(node* head, node* fast){
    node* slow = head;
    node* p = head;

    while(p->next != fast){
        p = p->next;
    }

    while(fast != slow){
        p = fast;
        fast = fast->next;
        slow = slow->next;
    }

    p->next = NULL;
}

bool isCyclic(node* head){ //Floyd's Cycle Detection Algorithm
    node* fast = head, *slow = head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            breakCycle(head, slow);
            return true;
        }
    }

    return false;
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
    
    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 6);
    insertAtEnd(head, tail, 7);
    insertAtEnd(head, tail, 8);

    tail->next = head->next->next;
    if(isCyclic(head)){
        cout << "It is cyclic\n";
    }
    else{
        cout << "It is not cyclic\n";
    }

    printLL(head);
}