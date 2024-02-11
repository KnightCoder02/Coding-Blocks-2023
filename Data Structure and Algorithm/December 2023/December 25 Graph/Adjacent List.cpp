#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool bidir = false){
        adj[u].push_back(v);
        if(bidir){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto p: adj){
            cout << p.first << " : ";
            for(auto n: p.second){
                cout << n << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Putin", "Trump", false);
    g.addEdge("Putin", "Modi", false);
    g.addEdge("Trump", "Modi", true);
    g.addEdge("Yogi", "Modi", true);
    g.addEdge("Yogi", "Prabhu", false);
    g.addEdge("Prabhu", "Modi", false);
    g.addEdge("Putin", "Pope", false);

    g.print();
}