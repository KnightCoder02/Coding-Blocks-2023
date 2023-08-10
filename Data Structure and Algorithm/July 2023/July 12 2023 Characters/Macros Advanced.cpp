#include<iostream>
using namespace std;
// Both macros are working and both loops are same
#define FOR(n) for(int i = 0; i < n; i++){ \
        cout << i << " "; \
    } \

#define LOOP(n) for(int i = 0; i < n; i++){ cout << i << " "; }


int main(){
    FOR(10);
    cout << endl;
    LOOP(10);
}