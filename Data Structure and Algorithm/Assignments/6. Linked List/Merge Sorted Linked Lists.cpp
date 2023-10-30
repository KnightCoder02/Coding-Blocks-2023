#include<iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeSortedLists(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode* current = &dummy;

    while(l1 && l2){
        if(l1->val < l2->val){
            current->next = l1;
            l1 = l1->next;
        }
        else{
            current->next = l2;
            l2 = l2->next;
        }

        current = current->next;
    }

    if(l1){
        current->next = l1;
    }
    else{
        current->next = l2;
    }

    return dummy.next;
}

// Function to print the merged linked list
void printMergedLinkedList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n1, n2;
        cin >> n1;
        ListNode* l1 = nullptr;
        ListNode* current = nullptr;
        
        for(int i = 0; i < n1; i++){
            int val;
            cin >> val;
            
            if(l1 == nullptr){
                l1 = new ListNode(val);
                current = l1;
            }
            else{
                current->next = new ListNode(val);
                current = current->next;
            }
        }

        cin >> n2;
        ListNode* l2 = nullptr;
        current = nullptr;
        
        for(int i = 0; i < n2; i++){
            int val;
            cin >> val;
            if(l2 == nullptr){
                l2 = new ListNode(val);
                current = l2;
            }
            else{
                current->next = new ListNode(val);
                current = current->next;
            }
        }

        ListNode* mergedList = mergeSortedLists(l1, l2);
        printMergedLinkedList(mergedList);
    }
}