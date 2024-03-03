#include<iostream>
#include<queue>
#include<climits>
using namespace std;

#define int long long

char a[26][26];
int x[] = {-1, 0, +1, 0};
int y[] = {0, +1, 0, -1};
int cols, rows;
int Time[26][26];

bool isValid(int i, int j){
    if(i >= 0 && j >= 0 && i < rows && j < cols && a[i][j] != 'X'){
        return true;
    }
    return false;
}

int shop(int i, int j, int di, int dj){
    queue<pair<int, int>> q;
    q.push({i, j});
    Time[i][j] = 0;

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        
        int ci = p.first;
        int cj = p.second;

        for(int k = 0; k < 4; k++){
            int ni = ci + x[k];
            int nj = cj + y[k];

            if(isValid(ni, nj) && Time[ni][nj] > Time[ci][cj] + (a[ni][nj] - '0')){
                Time[ni][nj] = Time[ci][cj] + (a[ni][nj] - '0');
                q.push({ni, nj});
            }
        }
    }
    return Time[di][dj];
}

void solve(){
    cin >> cols >> rows;
    while(cols && rows){
        int si, sj, di, dj;
        bool visited[26][26] = {0};

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cin >> a[i][j];
                Time[i][j] = INT_MAX;

                if(a[i][j] == 'S'){
                    si = i;
                    sj = j;
                    a[i][j] = '0';
                }

                if(a[i][j] == 'D'){
                    di = i;
                    dj = j;
                    a[i][j] = '0';
                }
            }
        }

        cout << shop(si, sj, di, dj) << endl;
        cin >> cols >> rows;
    }
}

int32_t main(){
    solve();
}