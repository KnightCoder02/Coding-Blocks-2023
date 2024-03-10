#include<iostream>
using namespace std;
class node{
    public:
    node* left; // If left child then 0 is present
    node* right; // If right child then 1 is present
    int no;

    node(){
        left = right = NULL;
    }
};

class Tries{
    public:
    node* root;

    Tries(){
        root = new node();
    }

    void insertNumber(int n){
        int i = 31;
        node* temp = root;

        while(i >= 0){
            if(n & (1 << i)){
                if(!temp->right){
                    temp->right = new node();
                }
                temp = temp->right;
            }

            else{
                if(!temp->left){
                    temp->left = new node();
                }
                temp = temp->left;
            }
            i--;
        }
        temp->no = n;
    }

    int findXorNumber(int n){
        node* temp = root;
        int i = 31;

        while(i >= 0){
            if(n & (1 << i)){
                if(temp->left){
                    temp = temp->left;
                }
                else{
                    temp = temp->right;
                }
            }

            else{
                if(temp->right){
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
            i--;
        }
        return temp->no;
    }

    int solve(int* a, int n){
        int ans = INT_MIN;
        
        for (int i = 0; i < n; i++){
            insertNumber(a[i]);
            int secans = findXorNumber(a[i]);
            ans = max(ans, a[i] ^ secans);
        }
        return ans;
    }
};

int main(){
    Tries t;
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);
    cout << t.solve(a, n) << endl;
}