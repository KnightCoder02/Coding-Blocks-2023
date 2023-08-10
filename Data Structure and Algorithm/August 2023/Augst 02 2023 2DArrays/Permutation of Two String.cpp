//Permutation --> Check all characters of Two String are equal or not

#include<iostream>
using namespace std;
bool isPermutation(char* a, char* b){
    int freq[26] = {0}, i = 0;

    //Calculate the index of String and increasing
    while(a[i] != '\0'){
        int index = a[i] - 'a';
        freq[index]++;
        i++;
    }

    //Decresing the index of String
    i = 0;
    while(b[i] != '\0'){
        int index = b[i] - 'a';
        freq[index]--;
        i++;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    char a[] = "abcdc", b[] = "ccbad";
    bool ans = isPermutation(a, b);

    if(ans == true){
        cout << "Permutation";
    }
    else{
        cout << "Not a Permutation";
    }
}