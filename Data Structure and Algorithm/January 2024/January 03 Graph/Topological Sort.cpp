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

    void topologicalSortHelper(T parent, unordered_map<T, bool> &visited, list<T> &ans){
        visited[parent] = true;

        for(auto children : adj[parent]){
            if(!visited[children]){
                topologicalSortHelper(children, visited, ans);
            }
        }

        ans.push_front(parent);
    }

    void topologicalSort(){
        unordered_map<T, bool> visited;
        list<T> ans;
        
        for(auto p : adj){
            if(!visited[p.first]){
                topologicalSortHelper(p.first, visited, ans);
            }
        }

        for(auto el : ans){
            cout << el << " ";
        }
        cout << endl;
    }

    // Topological Sorting using BFS
    void tpsBFS(){
        // Calculate inDegree
        unordered_map<T, int> indegree;

        for(auto p : adj){
            for(auto child : p.second){
                if(indegree.count(child) == 0){
                    indegree[child] = 1;
                }
                else{
                    indegree[child]++;
                }
            }
        }

        queue<T> q;
        for(auto p : adj){
            if(indegree[p.first] == 0){
                q.push(p.first);
            }
        }

        while(!q.empty()){
            T parent = q.front();
            cout << parent << " ";
            q.pop();

            for(auto child : adj[parent]){
                indegree[child]--;

                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }
        cout << endl;
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

    g.topologicalSort();
    g.tpsBFS();
}