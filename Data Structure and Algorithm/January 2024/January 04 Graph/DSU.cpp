#include<iostream>
#include<vector>
using namespace std;

class DSU{
    vector<int> parent;

    public:
    DSU(int v){
        parent.resize(v + 1);

        // Initially all are superParent / Leader / representative themselves.
        for(int i = 1; i <= v; i++){
            make_set(i);
        }
    }

    void make_set(int u){
        parent[u] = u;
    }

    // To return the leader of the u
    int find_set(int u){
        // base case
        if(u == parent[u]){
            return u;
        }

        // recursive case
        return find_set(parent[u]);
    }

    void union_set(int u, int v){
        int leader_u = find_set(u);
        int leader_v = find_set(v);

        parent[leader_v] = leader_u;
    }
};

int main(){
    DSU d(5);
    d.union_set(1, 2);
    d.union_set(3, 4);
    d.union_set(1, 3);

    cout << d.find_set(5);
}