#include<iostream>
#include<list> //This will create doubly linked list
using namespace std;
int main(){
    list<int> l;

    // Insertion in Linked list
    l.push_front(1);
    l.push_front(2);
    l.push_back(3);
    l.push_back(4);

    // Printing the Linked list
    cout << "NULL -- ";
    for(int d : l){
        cout << d << " -- ";
    }
    cout << "NULL" << endl;

    // Iteration on Linked list using iterator
    // Iterators are used to iterate over the containers.
    // Containers are nothing but I can say objects that we create using STL.

    list<int> :: iterator x;
    cout << "NULL -- ";
    for(x = l.begin(); x != l.end(); x++){
        cout << *x << " -- ";
    }
    cout << "NULL";

    // list<int> :: iterator y;
    cout << "NULL -- ";
    for(auto y = l.begin(); y != l.end(); y++){
        cout << *y << " -- ";
    }
    cout << "NULL";
}