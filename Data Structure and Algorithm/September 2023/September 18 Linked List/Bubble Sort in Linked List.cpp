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

// BUBBLE SORT IN LINKED LIST
void bubbleSort(node* &head){
    int n = lengthLL(head);
    for(int i = 0; i < n - 1; i++){
        node* c = head, *p = NULL;
        node* n;

        while(c != NULL && c->next != NULL){
            n = c->next;

            if(c->data > n->data){
                // Swapping
                if(p == NULL){
                    // Head changed
                    c->next = n->next;
                    n->next = c;
                    head = n;
                    p = n;
                }
                else{
                    // Head not changed
                    p->next = n;
                    c->next = n->next;
                    n->next = c;
                    p = n;
                }

            }
            else{
                // Not Swapping
                p = c;
                c = n;
            }
        }
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
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 6);
    printLL(head);

    bubbleSort(head);
}