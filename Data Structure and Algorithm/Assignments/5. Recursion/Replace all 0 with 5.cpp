#include<iostream>
#include<cmath>
using namespace std;

int replaceZerosWithFive(int num){
    if (num == 0) {
        return 5;
    }

    int result = 0;
    int decimalPlace = 1;

    while(num > 0){
        int digit = num % 10;
        
        if(digit == 0){
            result += 5 * decimalPlace;
        }
        else{
            result += digit * decimalPlace;
        }
        
        num /= 10;
        decimalPlace *= 10;
    }
    return result;
}

int main(){
    int N;
    cin >> N;

    int result = replaceZerosWithFive(N);
    cout << result << endl;
}