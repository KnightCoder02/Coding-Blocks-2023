#include <iostream>
using namespace std;

int nthTriangle(int n){
    if(n == 1){
        return 1;
    }

    return n + nthTriangle(n - 1);
}

int main(){
    int N;
    cin >> N;

    int result = nthTriangle(N);
    cout << result << endl;
}