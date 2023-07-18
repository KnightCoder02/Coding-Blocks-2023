#include<iostream>
using namespace std;
int main(){
    char ch;
    int space = 0, enter = 0;

    for(ch = cin.get(); ch != '$'; ch = cin.get()){
        if(ch == ' '){
            space++;
        }
        else if(ch == '\n'){
            enter++;
        }
    }

    cout << "Spaces: " << space << endl;
    cout << "Enter : " << enter << endl;
    cout << "Total number of words: " << space + enter + 1 << endl;
    cout << "Total number of lines: " << enter + 1 << endl;
}