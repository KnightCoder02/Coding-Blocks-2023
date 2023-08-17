#include<iostream>
using namespace std;
int maxSumPath(int* a, int n, int* b, int m){
    int i = 0, j = 0, ans = 0;
    int sumA = 0, sumB = 0;

    while(i < n && j < m){
        if(a[i] == b[j]){
            if(sumA > sumB){
                ans += sumA;
            }
            else{
                ans += sumB;
            }
            ans += a[i];
            sumA = 0;
            sumB = 0;
            i++;
            j++;
        }

        else if(a[i] < b[j]){
            sumA += a[i];
            i++;
        }

        else{
            sumB += b[j];
            j++;
        }
    }

    // If array a elements left then add to sumA
    while(i < n){
        sumA += a[i];
        i++;
    }

    // If array b elements left then add to sumB
    while(j < m){
        sumB += b[j];
        j++;
    }

    // After adding all elements of both arrays
    if(sumA > sumB){
        ans += sumA;
    }
    else{
        ans += sumB;
    }

    return ans;
}

int main(){
    int a[10000], b[10000];
    int n, m;
    int t;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        cout << maxSumPath(a, n, b, m);
    }
}