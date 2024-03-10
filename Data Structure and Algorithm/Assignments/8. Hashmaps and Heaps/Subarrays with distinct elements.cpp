#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    
    int N;
    cin >> N;
    int a[N];

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    int i = 0, j = 0, sum = 0;
    for(int i = 0; i < N; i++){
        while(j < N && s.find(a[j]) == s.end()){
            s.insert(a[j]);
            j++;
        }
        sum += ((j - i + 1) * (j - i)) / 2;
        s.erase(a[i]);
    }
    cout << sum;
}