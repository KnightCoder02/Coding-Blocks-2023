#include<iostream>
#include<set>
using namespace std;
int main(){
    // It sorts according to the first argument of pair
    // Updating is not possible in set
    set<pair<int, char>> s;
    s.insert({3, 'C'});
    s.insert({2, 'B'});
    s.insert({1, 'A'});
    s.insert({4, 'D'});

    // Updation in Set
    auto x = s.find({3, 'c'});
    if(x != s.end()){
        // Pair found. Delete x
        s.erase(x);
    }
    // If does not found then its okay. Now insert a new pair in set
    s.insert({5, 'E'});

    auto f = s.begin();
    while(!s.empty()){
        cout << (*f).first << ", " << (*f).second << endl;
        s.erase(f);
        f = s.begin();
    }
}
