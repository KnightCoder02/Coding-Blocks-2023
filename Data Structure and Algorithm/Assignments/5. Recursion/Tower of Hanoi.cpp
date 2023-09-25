#include <iostream>
using namespace std;
void towerOfHanoi(int N, char from, char to, char aux){
    if (N == 1) {
        cout << "Moving ring 1 from " << from << " to " << to << endl;
        return;
    }

    towerOfHanoi(N - 1, from, aux, to);
    cout << "Moving ring " << N << " from " << from << " to " << to << endl;
    towerOfHanoi(N - 1, aux, to, from);
}

int main(){
    int N;
    cin >> N;

    towerOfHanoi(N, 'A', 'B', 'C');
}