#include<iostream>
using namespace std;
int main(){
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(int); // 5 * 4(size of int) / 4(size of int)
    int count = 0;

    cout << "Before Sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    // Bubble Sort Algo
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= n - 2 - i; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                count++;
            }
        }

        if(count == 0){
            cout << "\nAlready Sorted" << endl;
            break;
        }
    }

    if(count != 0){
        cout << "\nAfter Sorting" << endl;
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
    }
}