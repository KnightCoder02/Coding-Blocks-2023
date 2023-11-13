#include <iostream>
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

void insert(node* &head, node* &tail, int data){
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

node* midLL(node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}

	node* slow = head;
	node* fast = head->next;

	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* mergeLL(node* a, node* b){
    if(!a){
        return b;
    }

    if(!b){
        return a;
    }

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

node* mergeSort(node* head){
    if(!head || !head->next){
        return head;
    }

    node *m = midLL(head);
    node* a = head;
    node* b = m->next;
    m->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    node* nH = mergeLL(a,b);
    return nH;
}

void printLL(node* temp){
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main(){
    node *head,*tail;
    node *head1,*tail1;
    
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        head = tail = NULL;
        head1 = tail1 = NULL;
        
        int n1, n2;
        cin >> n1;
        int data;
        
        for(int i = 0; i < n1; i++){
            cin >> data;
            insert(head, tail, data);
        }
        
        cin >> n2;
        for(int i = 0; i < n2; i++){
            cin >> data;
            insert(head1, tail1, data);
        }

        head = mergeLL(head, head1);
        node* nH = mergeSort(head);
        printLL(nH);
        cout << endl;
    }
}
