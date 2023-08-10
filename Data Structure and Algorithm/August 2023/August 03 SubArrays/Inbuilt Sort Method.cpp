#include<iostream>
#include<algorithm> //For inbuilt sort method
using namespace std;
bool cmp(int a, int b){
    //return a > b; //For Decending order
    return a < b; //For Ascending order
}

int main(){
    int a[] = {1, 6, 0, -1, 2, 3};
    int n = sizeof(a) / sizeof(int);

    sort(a, a + n); //First element is included and second element is excluded
    
    sort(a, a + n, cmp); //First element is address of index '1' and second element is address of index 'last element + 1' and cmp is for compare two values of array
    
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}