/*
    378 --> 3 + 7 + 8 = 18
    Prime factors of 378 = 2 + 3 + 3 + 3 + 7 = 18
    If sum of prime factors is equal to sum of digits of numbers than this is Boston Numbers
*/
#include<iostream>
using namespace std;
int main(){
    int no, no_copy, digit_sum = 0;
    cin >> no;
    no_copy = no;

    //Finding the digits sum
    while(no > 0){
        int ld = no % 10;
        digit_sum += ld;
        no /= 10;
    }

    no = no_copy;

    //Finding the sum of digits of prime factor of number
    int pf = 2, pf_digits_sum = 0;
    while(no > 1){
        while(no % pf == 0){
            int x = pf, pf_sum = 0;
            while(x > 0){
                int ld = x % 10;
                pf_sum += ld;
                x /= 10;
            }
            pf_digits_sum += pf_sum;
            no /= pf;
        }
        pf++;
    }
    
    if(digit_sum == pf_digits_sum){
        cout << "1";
    }
    else{
        cout << "0";
    }
}