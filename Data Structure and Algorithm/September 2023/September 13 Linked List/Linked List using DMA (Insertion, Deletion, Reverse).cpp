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
void insertAtFront(node* &head, node* &tail, int data){
    if(head == NULL){ //Linked List is empty
        node* n = new node(data);
        head = tail = n;
    }
    else{
        node* n = new node(data);
        n->next = head;
        head = n;
    }
}

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

void insertAtMiddle(node* &head, node* &tail, int pos, int data){
    if(pos == 0){
        insertAtFront(head, tail, data);
    }
    else if(pos >= lengthLL(head)){
        insertAtEnd(head, tail, data);
    }
    else{
        node* t = head;
        for(int i = 1; i <= pos - 1; i++){
            t = t->next;
        }

        node* n = new node(data);
        n->next = t->next;
        t->next = n;
    }
}

// DELETION IN LINKED LIST
void deleteAtFront(node* &head, node* tail){
    if(!head){
        cout << "Already deleted or does not exist";
        return;
    }
    else if(!head->next){
        delete head;
        head = tail = NULL;
    }
    else{
        node* t = head;
        head = head->next;
        delete t;
    }
}

void deleteAtEnd(node* head, node* tail){
    if(!head){
        return;
    }
    else if(!head->next){
        delete head;
        head = tail = NULL;
    }
    else{
        node* t = head;
        while(t->next != tail){
            t = t->next;
        }

        delete tail;
        tail = t;
        tail->next = NULL;
    }
}

void deleteAtMiddle(node* &head, node* &tail, int pos){
    if(pos == 0){
        deleteAtFront(head, tail);
    }
    else if(pos >= lengthLL(head) - 1){
        deleteAtEnd(head, tail);
    }
    else{
        node* t = head;
        for(int i = 1; i <= pos -1; i++){
            t = t->next;
        }

        node* n = t->next;
        t->next = n->next;
        delete n;
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
    
    insertAtFront(head, tail, 1);
    insertAtFront(head, tail, 2);
    insertAtFront(head, tail, 3);

    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 6);
    
    printLL(head);

    insertAtMiddle(head, tail, 4, 20);
    printLL(head);

    cout << "Length: " << lengthLL(head) << endl;

    deleteAtFront(head, tail);
    deleteAtEnd(head, tail);
    deleteAtMiddle(head, tail, 3);
    printLL(head);

    reverseLL(head, tail);
    printLL(head);

    reverseLLRec(head, tail);
    printLL(head);
}