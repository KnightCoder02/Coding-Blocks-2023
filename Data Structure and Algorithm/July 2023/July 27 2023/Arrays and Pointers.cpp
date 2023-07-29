#include<iostream>
using namespace std;
int main(){
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;

    for(int i = 0; i < 5; i++){
        cout << a[i] << " "; //a[i] == *(a + i)
        cout << *(a + i) << " ";
        cout << *(p + i) << " ";
        cout << p[i] << " ";
    }
}