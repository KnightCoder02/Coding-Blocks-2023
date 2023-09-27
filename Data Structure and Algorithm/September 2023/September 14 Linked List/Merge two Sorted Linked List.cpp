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

// MERGE TWO SORTED LINKED LIST
node* mergeLL(node* a, node* b){
    // Base case
    if(!a){
        return b;
    }

    if(!b){
        return a;
    }

    // Recursive case
    node* nH;
    if(a->data < b->data){
        nH = a;
        nH->next = mergeLL(a->next, b);
    }
    else{
        nH = b;
        nH->next = mergeLL(a, b->next);
    }
    return nH;
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

    node* head1, *tail1;
    head1 = tail1 = NULL;
    
    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 7);
    insertAtEnd(head, tail, 9);
    printLL(head);

    insertAtEnd(head1, tail1, 2);
    insertAtEnd(head1, tail1, 4);
    insertAtEnd(head1, tail1, 6);
    insertAtEnd(head1, tail1, 8);
    insertAtEnd(head1, tail1, 10);
    printLL(head1);

    head = mergeLL(head, head1);
    printLL(head);
}