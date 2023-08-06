#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[] = {1, 0, -1, 0, -2, 2};
    int n = sizeof(a) / sizeof(int);
    
    sort(a, a + n);
    int target = 0;

    for(int i = 0; i < n - 2; i++){
        if(i > 0 && a[i] == a[i - 1]){
            continue;
        }

        for(int l = i + 1; l < n - 2; l++){
            if(a[l] == a[l - 1]){
                continue;
            }
            
            int j = l + 1;
            int k = n - 1;

            while(j < k){
                if(a[i] + a[j] + a[k]  + a[l] < target){
                    j++;
                }
            
                else if(a[i] + a[j] + a[k] + a[l] > target){
                    k--;
                }
            
                else{
                    cout << a[i] << ", " << a[j] << ", " << a[k] << ", " << a[l] << endl;
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
}