// Write a function which returns the LCM of N1 and N2. Print the value returned.
#include <iostream>
using namespace std;
int main()
{
    int num1, num2, max;
    cin >> num1 >> num2;
    max = (num1 > num2) ? num1 : num2;

    do{
        if (max % num1 == 0 && max % num2 == 0){
            cout << max;
            break;
        }
        else{
            ++max;
        }
    } while (true);
}