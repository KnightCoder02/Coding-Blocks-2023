//Permutation --> Check all characters of Two String are equal or not

#include<iostream>
using namespace std;
bool isPermutation(char* a, char* b){
    int freq[256] = {0}, i = 0;

    //Calculate the index of String and increasing
    while(a[i] != '\0'){
        freq[a[i]]++;
        i++;
    }

    //Decresing the index of String
    i = 0;
    while(b[i] != '\0'){
        freq[b[i]]--;
        i++;
    }

    for(int i = 0; i < 256; i++){
        if(freq[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    char a[] = "AABBccdd", b[] = "AaBbCc";
    bool ans = isPermutation(a, b);

    if(ans == true){
        cout << "Permutation";
    }
    else{
        cout << "Not a Permutation";
    }
}