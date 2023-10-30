#include<iostream>
using namespace std;
class Solution{
    public:
    bool knows(int a, int b){
        int ar[100][100];
        return ar[a][b];
    }

    bool isCeleb(int p, int n){
        for(int i = 0; i < n; i++){
            if(i == p){
                continue;
            }

            if(knows(p, i) || !knows(i, p)){
                return false;
            }
        }
        return true;
    }

    int findCelebrity(int n){
        int person;
        int l = 0, r = n - 1;
        while(l < r){
            if(knows(l, r) == true){
                // This means l cannot be a celebrity
                l++;
            }
            else{
                // This means r cannot be a celebrity
                r--;
            }
        }

        // l and r are equal then find the celebrity
        if(isCeleb(l, n)){
            return l;
        }
        return -1;
    }
};

int main(){

}