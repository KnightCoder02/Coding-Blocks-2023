#include<iostream>
using namespace std;
int main(){
    int a[] = {1, -5, 2, 4, -3, 10, -20};
    int n = sizeof(a) / sizeof(int);
    int s = 0;
    int ans = 0;

// T.C: 0(N)
    for(int i = 0; i < n; i++){
        s += a[i];
        if(s < 0){
            s = 0;
        }

        ans = max(ans, s); 
    }

    cout << "Max sum: " << ans << endl;
}