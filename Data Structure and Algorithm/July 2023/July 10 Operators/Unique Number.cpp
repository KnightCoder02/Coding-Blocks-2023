/*
Given N numbers, all the numbers occur twice except 1 number, find the number that occurs only once.

Example: 1, 2, 3, 2, 1
Answer: 3

Example: 1, 3, 2, 4, 1, 2, 3
Answer: 4
*/

#include<iostream>
using namespace std;
int main(){
    int n, i = 1, ans = 0, no;
    cin >> n;

    while(i <= n){
        cin >> no;
        ans = ans ^ no;
        i++;
    }
    cout << ans;
}