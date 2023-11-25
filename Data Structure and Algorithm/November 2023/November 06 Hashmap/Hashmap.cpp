#include<iostream>
using namespace std;
class node{
    public:
    int data;
    string key;
    node* next;

    node(string k, int d){
        key = k;
        data = d;
    }
};

class hashmap{
    int hashFunction(string s){
        int ans = 0, mul = 1;
        for(int i = 0; i < s.size(); i++){
            ans += ((s[i] % ts) * (mul % ts)) % ts;
            mul = ((mul % ts) * (37 % ts)) % ts;
        }
        return ans % ts;
    }

    void rehashing(){
        // Old data is important that's why store old data to save from memory leak
        node** olda = a;
        int oldts = ts;

        // Make a new array of size 2 * ts
        a = new node*[2*ts];
        ts = ts * 2;

        cs = 0;
        for(int i = 0; i < oldts; i++){
            node* head = olda[i];
            
            while(head != NULL){
                insert(head->key, head->data);
                head = head->next;
            }
        }
    }

    public:
    node** a;
    int ts;
    int cs;

    hashmap(int t = 7){
        a = new node*[t];
        ts = t;
        cs = 0;

        for(int i = 0; i < ts; i++){
            a[i] = NULL;
        }
    }

    void insert(string key, int value){
        // 1. Convert key to integer
        int hashIndex = hashFunction(key);

        // 2. We need to store the key and value node at hashIndex of array a[]
        node* n = new node(key, value);
        n->next = a[hashIndex];
        a[hashIndex] = n;
        cs++;

        float load_factor = cs / (ts * 1.0);
        if(load_factor > 0.5){
            // If table is filled more than 50%
            rehashing();
        }
    }

    void print(){
        for(int i = 0; i < ts; i++){
            cout << i << "-->";
            node* head = a[i];
            
            while(head != NULL){
                cout << "(" << head->key << ", " << head->data << ") ";
                head = head->next;
            }
            cout << endl;
        }
    }

    node* search(string key){
        int hashIndex = hashFunction(key);
        node* head = a[hashIndex];
        
        while(head != NULL){
            if(head->key == key){
                return head;
            }
            head = head->next;
        }
        return NULL; // or return head; // since head == NULL;
    }

    int& operator[](string key){
        node* x = search(key);
        if(x == NULL){
            int g;
            insert(key, g); //g can be anything because it will update when return bucket to main
            x = search(key);
            return x->data;
        }
        return x->data;
    }
};

int main(){
    hashmap h;
    h.insert("Mango", 100);
    h.insert("Apple", 150);
    h.insert("Mausami", 90);
    h.insert("Pineapple", 900);
    
    h["Guava"] = 20; //Insertion
    h["Guava"] = 200; //Updation
    cout << h["Guava"] << endl; //Search

    h.print();
}