#include<iostream>
using namespace std;
int main(){
    string a;
    getline(cin, a);

    for(int i = 0; i < a.size();){
        char ch = a[i];
        int count = 1;

        int j = i + 1;
        while(j < a.size() && a[j] == ch){
            j++;
            count++;
        }

        cout << ch << count;
        i = j;
    }
}