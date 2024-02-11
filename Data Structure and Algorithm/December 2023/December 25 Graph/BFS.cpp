#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool bidir = true){
        adj[u].push_back(v);
        if(bidir){
            adj[v].push_back(u);
        }
    }

    void BFS(T src, T des){
        unordered_map<T, int> distance;
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;

        distance[src] = 0;
        parent[src] = src;
        visited[src] = true;

        queue<T> q;
        q.push(src);


        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout << node << "   ";

            for(auto neighbour : adj[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    distance[neighbour] = distance[node] + 1;
                    parent[neighbour] = node;
                    visited[neighbour] = true;
                }
            }
        }
        cout << endl;
        
        cout << "PRINTING ALL DISTANCES:\n";
        for(auto p : distance){
            cout << "Distance of " << p.first << " from " << src << " is " << p.second << endl;
        }

        cout << "PATH: ";
        while(des != parent[des]){
            cout << des << " <-- ";
            des = parent[des];
        }
        cout << des << endl;
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.BFS(0, 5);
}