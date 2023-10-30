#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x){
    ListNode less_head(0); // Dummy head for the list with values less than x
    ListNode greater_head(0); // Dummy head for the list with values greater than or equal to x
    ListNode* less_ptr = &less_head;
    ListNode* greater_ptr = &greater_head;

    while(head != nullptr){
        if(head->val < x){
            less_ptr->next = head;
            less_ptr = less_ptr->next;
        }
        else{
            greater_ptr->next = head;
            greater_ptr = greater_ptr->next;
        }
        head = head->next;
    }

    greater_ptr->next = nullptr; // Set the end of the greater list
    less_ptr->next = greater_head.next; // Connect the less list to the greater list

    return less_head.next; // Return the merged list
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n){
    ListNode dummy(0);
    ListNode* current = &dummy;
    for(int i = 0; i < n; i++){
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return dummy.next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int n, x;
    cin >> n >> x;
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ListNode* head = createLinkedList(arr, n);
    ListNode* result = partition(head, x);
    printLinkedList(result);
}