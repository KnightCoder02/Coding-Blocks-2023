#include<iostream>
using namespace std;
int main(){
    int a[] = {4, 2, 6, 5, 0, 1, -1, 5};
    int n = sizeof(a) / sizeof(int);

    cout << "Before Sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    // Insertion Logic
        for(int j = 0; j <= n - 1; j++){
            int cur_card = a[j];
            int pos = j - 1;
            while(pos >= 0){
                if(cur_card < a[pos]){
                    a[pos + 1] = a[pos];
                }
                else{
                    break;
                }
                pos--;
            }
            a[pos + 1] = cur_card;
        }

    cout << "After Sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

}