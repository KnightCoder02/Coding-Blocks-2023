#include <iostream>
using namespace std;

class MyClass{
    public:
    void solve(int n, int sums){
        if(sums > n){
            return;
        }

        cout << sums << " ";
        
        if(sums == 0){
            for(int i = 1; i < 10; ++i){
                solve(n, 10 * sums + i);
            }
        }
        else{
            for(int i = 0; i < 10; ++i){
                solve(n, 10 * sums + i);
            }
        }
    }
};

int main(){
    int n;
    cin >> n;

    MyClass obj;
    obj.solve(n, 0);
}