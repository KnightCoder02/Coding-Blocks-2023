#include<iostream>
using namespace std;
int main(){
    int a[1000], n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int target;
    cin >> target;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] + a[j] == target){
                if(a[i] < a[j]){
                    cout << a[i] << " and " << a[j] << endl;
                }
                else{
                    cout << a[j] << " and " << a[i] << endl;
                }
            }
            
        }
    }
}