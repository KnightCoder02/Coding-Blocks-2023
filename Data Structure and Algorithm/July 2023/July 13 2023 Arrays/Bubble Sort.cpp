#include<iostream>
using namespace std;
int main(){
    int a[] = {2, 1, 5, 4, 3};
    int n = sizeof(a) / sizeof(int); // 5 * 4(size of int) / 4(size of int)

    cout << "Before Sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    // Bubble Sort Algo
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= n - 2; j++){
            if(a[j] > a[j+1]){

                // Swapping 1 method
                // int temp = a[j];
                // a[j] = a[j+1];
                // a[j+1] = temp;

                // Swapping 2 method
                // a[j] = a[j] + a[j+1];
                // a[j+1] = a[j] - a[j+1];
                // a[j] = a[j] - a[j+1];

                // Swapping 3 method
                // a[j] = (a[j] + a[j+1]) - (a[j+1] = a[j]);

                // Swapping 4 method
                swap(a[j], a[j+1]);
            }
        }
    }

    cout << "\nAfter Sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}