#include<iostream>
using namespace std;

typedef long long ll;
ll findans(ll a[], ll n){
    ll max1 = 0;
    ll lis[n];
    
    for(ll i = 0; i < n; i++){
        lis[i] = 1;
    }

    ll right = 0;
    ll left = 0;
    
    for(ll i = 1; i < n; i++){
        for(ll j = 0; j < i; j++){
            if(a[i] > a[j]){
                lis[i] = max(lis[i], lis[j] + 1);
                
                if(max1 < lis[i]){
                    left = i;
                    right = j;
                    max1 = lis[i];
                }
            }
        }
    }    
    return max1;
}

int main(){
    ll n;
    cin >> n;
    
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cout << findans(a, n) << endl;
}