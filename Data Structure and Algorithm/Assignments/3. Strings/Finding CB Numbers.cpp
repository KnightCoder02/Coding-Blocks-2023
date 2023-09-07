#include<iostream>
using namespace std;
long long stringToInt(string& s, int n){
    //base case
    if(n==0){
        return 0;
    }
    return stringToInt(s,n-1) * 10 + (s[n-1] - '0');
}

bool isCBNumber(long long num){
    // 1st case
    if(num==0 || num==1){
        return false;
    }

    // second case
    int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for(int i = 0; i < 10; i++){
        if(a[i] == num){
            return true;
        }
    }

    // third case
    for(int i = 0; i < 10; i++){
        if(num % a[i] == 0){
            return false;
        }
    }
    return true;
}

bool valid(int *visited, int st, int en){
    for(int i = st; i <= en; i++){
        if(visited[i] == 1){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    int ct = 0;
    int visited[100] = {0};
    
    for(int len = 1; len <= s.length(); len++){
        for(int st = 0; (st + len - 1) < n; st++){
            int en = st + len - 1;
            string subs = "";
            
            for(int i = st; i <= en; i++){
                subs += s[i];
            }
            long long num = stringToInt(subs, len);
            if(isCBNumber(num) == true && valid(visited, st, en) == true){
                for(int i = st; i <= en; i++){
                    visited[i] = 1;
                }
                ct++;
            }
        }
    }
    cout << ct << endl;
}