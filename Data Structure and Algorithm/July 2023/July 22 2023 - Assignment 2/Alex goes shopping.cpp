#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int price[100000];
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }

    int query;
    int amount, key;
    cin >> query;

    for(int i = 0; i < query; i++){
        cin >> amount >> key;
        int count = 0;

        for(int j = 0; j < n; j++){
            if((amount % price[j]) == 0){
                count++;
            }
            if(count == key){
                cout << "Yes" << endl;
                break;
            }
        }
        if(count < key){
            cout << "No" << endl;
        }
    }
}