// Sum of triplets = 0
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[] = {-1, -1, 0, 1, 2, 4, -2, -2};
    int n = sizeof(a) / sizeof(int);
    
    sort(a, a + n);

    for(int i = 0; i < n - 2; i++){
        int j = i + 1;
        int k = n - 1;

        while((i > 0) && (i < n - 2) && (a[i] == a[i - 1])){
            i++;
        }

        while(j < k){
            if(a[i] + a[j] + a[k] == 0){
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

            else{
                if(a[i] + a[j] + a[k] < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
    }
}