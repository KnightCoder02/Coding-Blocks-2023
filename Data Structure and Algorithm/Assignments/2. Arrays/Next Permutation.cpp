#include<iostream>
#include<algorithm>
using namespace std;
void next(char* a, int n){
    int i = n - 2;

    while(a[i] >= a[i + 1]){
        i--;
    }

    if(i == -1){
        sort(a, a + n);
        
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else{
        // Find element which is just big than ith element
        int index = -1;
        
        for(int j = i + 1; j < n; j++){
            if(a[j] > a[i] && index == -1){
                index = j;
            }
            else if(a[j] > a[i] && a[j] < a[index]){
                index = j;
            }
        }

        swap(a[i], a[index]);
        sort(a + i + 1, a + n);
        
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    char a[10000];
    int t;
    cin >> t;

    while(t--){
        int n, i;
        cin >> n;

        for(i = 0; i < n; i++){
            cin >> a[i];
        }
        a[i] = '\0';
        next(a, n);
    }
}