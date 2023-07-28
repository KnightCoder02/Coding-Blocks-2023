#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

void update(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        v[i] += 100;
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    update(v);
    print(v);

    vector<int> m(n, 10);
    cout << endl;
    print(m);
    cout << endl;
    cout << m.capacity() << endl;
    m.push_back(1);
    cout << m.capacity() << endl;
}