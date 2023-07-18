#include<iostream>
using namespace std;
int main(){
    char ch;
    int count = 0;

    cin >> ch;
    while(ch != '$'){
        count++;
        cin >> ch;
    }

    cout << "Number of characters before $: " << count;
}