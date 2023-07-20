#include<iostream>
using namespace std;
int main(){
    int a[] = {0, 3, 2, 5, 4, 1};
    int n = sizeof(a) / sizeof(int);

    cout << "Before Sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    // Selection Sort
    for(int pos = 0; pos <= n - 1; pos++){
        int min = pos;
        for(int j = pos + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(a[min], a[pos]);
    }

    cout << "After Sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}