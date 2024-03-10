#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Pair{
    public:
    int fre;
    int value;
};

class PairCompare{
    public:
    bool operator()(Pair A, Pair B){
        if(A.fre == B.fre){
            return A.value > B.value;
        }
        return A.fre < B.fre;
    }
};

void remove_d(priority_queue<Pair, vector<Pair>, PairCompare> &pq, int d, int k){
    if(pq.empty() or k == 0){
        return;
    }
    
    if(pq.top().value == d){
        pq.pop();
        return;
    }

    Pair p = pq.top();
    pq.pop();
    remove_d(pq, d, k - 1);
    pq.push(p);
}

void PrintQueue(priority_queue<Pair, vector<Pair>, PairCompare> &pq, int k){
    if(pq.empty() or k == 0){
        return;
    }
    
    Pair p = pq.top();
    pq.pop();
    cout << p.value << " ";
    PrintQueue(pq, k - 1);
    pq.push(p);
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int a[100005] = {0};
        int n, k;
        cin >> n >> k;
        
        priority_queue<Pair, vector<Pair>, PairCompare> pq;
        for(int i = 0; i < n; i++){
            int d;
            cin >> d;
            
            Pair p;
            if(a[d] == 0){
                a[d] = a[d] + 1;
                p.fre = 1;
                p.value = d;
                pq.push(p);
            }
            else{
                a[d] = a[d] + 1;
                remove_d(pq, d, k);
                p.fre = a[d] + 1;
                p.value = d;
                pq.push(p);
            }

            PrintQueue(pq, k);
        }

        cout << endl;
    }
}