// Sum of triplets = 0
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[] = {-1, -1, 0, 1, 2, 4, -2, -2};
    int n = sizeof(a) / sizeof(int);
    
    sort(a, a + n);

    for(int i = 0; i < n - 2; i++){
        if(i > 0 && a[i] == a[i - 1]){
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while(j < k){
            if(a[i] + a[j] + a[k] < 0){
                j++;
            }
            
            else if(a[i] + a[j] + a[k] > 0){
                k--;
            }
            
            else{
                cout << a[i] << ", " << a[j] << ", " << a[k] << endl;
                j++;
                k--;
                
                while(j < k && a[j] == a[j - 1]){
                    j++;
                }

                while(k > j && a[k] == a[k + 1]){
                    k--;
                }
            }
        }
    }
}