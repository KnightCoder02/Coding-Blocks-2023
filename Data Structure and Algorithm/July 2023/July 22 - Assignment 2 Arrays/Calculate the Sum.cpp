#include<iostream>
using namespace std;
int mod = 1e9 + 7;
int main(){
    int n;
    cin >> n;

    long long* a = new long long[n];
    long long* b = new long long[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int q, x;
    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> x;
        x = x % n;
        
        for(int j = 0; j < n; j++){
            int pos = j - x;
            if(pos < 0){
                pos += n;    
            }

            b[j] = (a[j] + a[pos]) % mod;
        }
        for(int j = 0; j < n; j++){
            a[j] = b[j];
        }
    }

    long long sum = 0LL;
    for(int i = 0; i < n; i++){
        sum = (sum + a[i]) % mod;
    }
    cout << (sum % mod);
    delete[] a;
    delete[] b;
}