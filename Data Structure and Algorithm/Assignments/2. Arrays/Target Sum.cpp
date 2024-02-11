#include<iostream>
#include<vector>
using namespace std;

int countWays(vector<int> &zeni, int n, int target){
    int count = 0;

    for(int i = 0; i < (1 << n); i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                sum += zeni[j];
            } 
            else{
                sum -= zeni[j];
            }
        }

        if(sum == target){
            count++;
        }
    }
    return count;
}

int main(){
    int n, target;
    cin >> n >> target;

    vector<int> zeni(n);

    for (int i = 0; i < n; i++) {
        cin >> zeni[i];
    }

    int ways = countWays(zeni, n, target);
    cout << ways << endl;
}
