#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

bool findTriplet(ListNode* a, ListNode* b, ListNode* c, int target){
    while(a){
        ListNode* cur_b = b;
        while(cur_b){
            ListNode* cur_c = c;
            while(cur_c){
                int sum = a->val + cur_b->val + cur_c->val;
                
                if(sum == target){
                    cout << a->val << " " << cur_b->val << " " << cur_c->val << endl;
                    return true;
                }

                cur_c = cur_c->next;
            }

            cur_b = cur_b->next;
        }

        a = a->next;
    }
    return false;
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    for(int i = 0; i < n; i++){
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return dummy.next;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int arr1[n], arr2[m], arr3[k];
    
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    for(int i = 0; i < k; i++){
        cin >> arr3[i];
    }

    int target;
    cin >> target;

    ListNode* a = createLinkedList(arr1, n);
    ListNode* b = createLinkedList(arr2, m);
    ListNode* c = createLinkedList(arr3, k);

    if(!findTriplet(a, b, c, target)){
        cout << "No triplet found." << endl;
    }
}