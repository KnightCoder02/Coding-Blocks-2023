#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* appendKLastElements(ListNode* head, int N, int K){
    if(K <= 0){
        return head;
    } 

    K %= N;
    if(K == 0){
        return head;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;
    for(int i = 0; i < N - K; i++){
        prev = current;
        current = current->next;
    }

    prev->next = nullptr;
    ListNode* newHead = current;
    ListNode* newTail = prev;

    while(current->next != nullptr){
        current = current->next;
    }

    current->next = head;
    return newHead;
}

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){
    int N;
    cin >> N;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i = 0; i < N; i++){
        int val;
        cin >> val;

        if(head == nullptr){
            head = new ListNode(val);
            tail = head;
        }
        else{
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }

    int K;
    cin >> K;

    head = appendKLastElements(head, N, K);
    printList(head);
}