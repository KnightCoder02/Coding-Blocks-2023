#include<iostream>
#include<unordered_map>
using namespace std;
class node{
    public:
    char ch;
    unordered_map<char, node*> h;
    bool wordEnd;

    node(char c){
        ch = c;
        wordEnd = false;
    }
};

class Tries{
    public:
    node* root;
    Tries(){
        // Initialize the root node with character null
        root = new node('\0');
    }

    void insertWord(char *word){
        node* temp = root;
        
        for(int i = 0; word[i] != '\0'; i++){
            char ch = word[i];

            if(temp->h.count(ch) == 1){
                temp = temp->h[ch];
            }
            else{
                node* n = new node(ch);
                temp->h[ch] = n;
                temp = temp->h[ch];
            }
        }

        // Mark node that word ends at where temp is present
        temp->wordEnd = true;
    }

    bool isPresent(char *word){
        node* temp = root;
        
        for(int i = 0; word[i] != '\0'; i++){
            char ch = word[i];

            if(temp->h.count(ch) == 1){
                temp = temp->h[ch];
            }
            else{
                return false;
            }
        }
        return temp->wordEnd;
    }
};

int main(){
    Tries t;
    t.insertWord("Hello");
    t.insertWord("He");
    t.insertWord("Her");
    t.insertWord("Bat");
    t.insertWord("Babe");
    t.insertWord("Mat");

    while(true){
        char a[100];
        cin >> a;

        if(t.isPresent(a) == true){
            cout << "Present\n";
        }
        else{
            cout << "Not Present\n";
        }
    }
}