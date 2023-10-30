#include<iostream>
#include<queue>
#include<unordered_set>
#include<cstring>
#include<climits>
using namespace std;

#define s(x) scanf("%lld", &x)
#define s2(x, y) s(x) + s(y)
long long int mod = 1e9 + 7 ;

long long int gcd(long long int a , long long int b){
    return b == 0? a : gcd(b, a % b);
}

int main(){
    long long int q;
    s(q);

    // tot[0] will contain the overall timestamp
    // tot[i] will contain the timestamp for the ith course for i>0
    long long int tot[5];
    memset(tot, -1, sizeof(tot));
    tot[0] = 0;

    // qu[i] will contain the students of the ith course in the order of their entry 
    queue<long long int> qu[5];
    while(q--){
        char ch;
        cin >> ch;
    
        if(ch == 'E'){
            long long int x, r;
            s2(x, r);

            // Increase the overall timestamp
            tot[0]++;

            // Push the child in the xth course's queue
            qu[x].push(r);

            // If the student is the first student in the course, set the timestamp of the xth course to that of the overall time stamp
            if(tot[x] == -1){
                tot[x] = tot[0];
            }
        }
        else{
            long long int id = 0;
            long long int mini = INT_MAX;
            
            // Simply compute the course with the minimum timestamp 
            for(long long int i = 1; i <= 4; i++){
                if(tot[i] != -1 && tot[i] < mini){
                    mini = tot[i];
                    id = i;
                }
            }
      
            cout << id << " " << qu[id].front() << endl;

            // Ppp the child from the course with the least timestamp
            qu[id].pop();

            // If that was the only child in the course, reset the timestamp of that course to -1.
            if(qu[id].empty()){
                tot[id] = -1;
            }
        }
    }
}