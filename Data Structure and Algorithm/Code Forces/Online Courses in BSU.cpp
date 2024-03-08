#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
#include<list>
#include<vector>
using namespace std;

#define pb push_back
map<int, list<int>> adj;
vector<int> coursesToDo;
int n, k;
int coursesStatus[100005] = {0};
vector<int> ans;

void addEdge(int u, int v){
    adj[u].pb(v);
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

void takeInput(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        coursesToDo.pb(x);
    }

    for(int u = 1; u <= n; u++){
        int m;
        cin >> m;
        
        if(!m){
            continue;
        }

        for(int i = 0; i < m; i++){
            int v;
            cin >> v;
            adj[u].pb(v);
        }
    }
}

// Algorithm
bool bsuHelper(int course){
    // If course is already done
    if(coursesStatus[course] == 2){
        return false;
    }

    // If course is going on
    coursesStatus[course] = 1;

    for(auto dependentCourse : adj[course]){
        if(coursesStatus[dependentCourse] == 1){
            // If dependent course is going on, therefore, cycle comes
            return true;
        }

        bool cycle = bsuHelper(dependentCourse);
        if(cycle == true){
            return true;
        }
    }

    // Cuurent course is already done
    coursesStatus[course] = 2;
    ans.pb(course);
    return false;
}

bool bsu(){
    for(auto course : coursesToDo){
        if(coursesStatus[course] == 0){
            bool isCyclic = bsuHelper(course);

            if(isCyclic){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    takeInput();
    
    bool cycle = bsu();
    if(cycle){
        cout << "-1\n";
    }
    else{
        cout << ans.size() << "\n";
        for(auto x : ans){
            cout << x << " ";
        }
        cout << endl;
    }
}