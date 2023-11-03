#include<iostream>
using namespace std;
// Define the structure of a linked list node
struct Node{
    int data;
    Node* next;
};

// Function to append the last K elements of the linked list to the front
Node* appendLastKToFront(Node* head, int k){
    if(head == nullptr || k <= 0){
        return head;
    }

    // Count the number of nodes in the linked list
    int count = 0;
    Node* current = head;
    while(current != nullptr){
        count++;
        current = current->next;
    }

    // If K is greater than or equal to the number of nodes, no change is required
    if (k >= count){
        return head;
    }

    // Find the node that will become the new head after appending the last K nodes
    current = head;
    for(int i = 0; i < count - k - 1; i++){
        current = current->next;
    }

    // Update pointers to create the new linked list
    Node* newHead = current->next;
    current->next = nullptr;

    // Find the last node in the original list and link it to the original head
    Node* temp = newHead;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = head;
    return newHead;
}

// Function to print the linked list
void printList(Node* head){
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    int n, k;
    cin >> n;
    
    Node* head = nullptr;
    Node* tail = nullptr;

    // Input the elements and create the linked list
    for(int i = 0; i < n; i++){
        int data;
        cin >> data;
        
        Node* newNode = new Node{data, nullptr};
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    cin >> k;

    // Append the last K elements to the front
    head = appendLastKToFront(head, k);

    // Print the modified linked list
    printList(head);
}