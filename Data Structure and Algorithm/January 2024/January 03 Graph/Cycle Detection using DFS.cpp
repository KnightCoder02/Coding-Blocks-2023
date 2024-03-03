#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
#include<list>
using namespace std;

#define pb push_back
template<typename T>
class Graph{
    public:
    map<T, list<T>> adj;

    void addEdge(T u, T v, bool bidir = true){
        adj[u].pb(v);

        if(bidir){
            adj[v].pb(u);
        }
    }

    void print(){
        for(auto p : adj){
            cout << p.first << " : ";

            for(auto x : p.second){
                cout << x << " ";
            }
            cout << endl;
        }
    }

    bool isCyclicDFSHelper(T src, unordered_map<T, bool> &visited, unordered_map<T, bool> &currentPath){
        currentPath[src] = true;
        visited[src] = true;

        for(auto neighbours : adj[src]){
            if(currentPath[neighbours]){
                return true;
            }

            else if(!visited[neighbours]){
                bool ans = isCyclicDFSHelper(neighbours, visited, currentPath);
                
                if(ans == true){
                    return true;
                }
            }
        }

        currentPath[src] = false;
        return false;
    }

    bool isCyclicDFS(){
        unordered_map<T, bool> visited;
        unordered_map<T, bool> currentPath;

        for(auto p : adj){
            if(!visited[p.first]){
                bool ans = isCyclicDFSHelper(p.first, visited, currentPath);

                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph<string> g;
    g.addEdge("HTML", "JS", false);
    g.addEdge("JS", "Web", false);
    g.addEdge("MATHS", "C++", false);
    g.addEdge("C++", "DSA", false);
    g.addEdge("DSA", "Web", false);
    g.addEdge("DSA", "CP", false);
    g.addEdge("Web", "Job", false);
    g.addEdge("CP", "Job", false);

    cout << g.isCyclicDFS();
}