#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define MAX 1299709 //10^5 th prime number
 
void createSieve(vector<int> &primes){
    vector<bool> sieve(MAX, true);
    sieve[0] = sieve[1] = false;
    for(long long int i = 2; i < MAX; i++){
        if(sieve[i]){
            primes.push_back(i);
            
            for(long long int j = i * i; j < MAX; j += i){
                sieve[j] = false;
            }
        }
    }
}

int main(){
    vector<int> primes;
    createSieve(primes);
    
    int n, q;
    cin >> n >> q;
    stack<int> s;
 
    while(n--){
        int d;
        cin >> d;
        s.push(d);
    }
 
    stack<int> a;
    stack<int> b;
    queue<int> qu;
 
    for(int i = 1; i <= q; i++){
        while(!s.empty()){
            int x = s.top();
            int y = primes[i - 1];
            
            if(x % y == 0){
                b.push(x);
            }
            else{
                a.push(x);
            }
            s.pop();
        }
        
        while(!b.empty()){
            int x = b.top();
            qu.push(x);
            b.pop();
        }

        swap(s, a);
    }

    while(!qu.empty()){
        cout << qu.front() << endl;
        qu.pop();
    }

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}