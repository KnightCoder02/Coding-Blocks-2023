#include<iostream>
using namespace std;
int add(int x, int y){
    int sum = x + y;
    return sum;
}

void printsum(int a, int b){
    cout << "\nSum: " << a + b;
}

void helloworld(){
    cout << "Hello World";
}

int main(){
    helloworld();

    int x = 10, y = 20;
    printsum(x, y);
    printsum(30, 40);

    int a = 10, b = 20;
    int c = add(a, b);
    cout << "\nSum: " << c << endl;
    c % 2 == 0? cout << "Sum is even" : cout << "Sum is odd";
}