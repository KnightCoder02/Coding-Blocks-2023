#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getDecimalValue(ListNode* head){
    int result = 0;
    while(head){
        result = result * 2 + head->val;
        head = head->next;
    }
    return result;
}

int main(){
    int n;
    cin >> n;

    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(!head){
            head = new ListNode(val);
            current = head;
        }
        else{
            current->next = new ListNode(val);
            current = current->next;
        }
    }

    int decimalValue = getDecimalValue(head);
    cout << decimalValue << endl;
}