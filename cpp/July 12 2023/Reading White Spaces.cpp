#include<iostream>
using namespace std;
int main(){
    /*
    To take white space character input
    use: ch = cin.get()
    instead of cin >> ch;
    */
    char ch;
    int count = 0;
    
    ch = cin.get();
    while(ch != '\n'){
        count++;
        cout << ch;
        ch = cin.get();
    }

    cout << "Number of Characters: " << count;
}
