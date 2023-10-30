#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* reverseKGroup(Node* head, int k){
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    // Count the number of nodes in the current group
    Node* temp = head;
    while(temp && count < k){
        temp = temp->next;
        count++;
    }

    // If there are at least k nodes, reverse the current group
    if(count == k){
        while(current && count > 0){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count--;
        }

        // Recursively reverse the remaining list
        if(next){
            head->next = reverseKGroup(next, k);
        }

        return prev;
    } 
    
    else{
        return head;
    }
}

void printList(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){
    int n, k;
    cin >> n >> k;
    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < n; i++){
        int data;
        cin >> data;
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseKGroup(head, k);
    printList(head);
}