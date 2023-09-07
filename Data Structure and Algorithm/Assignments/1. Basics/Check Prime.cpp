// Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".
#include<iostream>
using namespace std;
int main() {
	int n, i = 2;
	cin >> n;

	while(i <= n - 1){
		if(n % i == 0){
			cout << "Not Prime";
			return 0;
		}
		i = i + 1;
	}
	cout << "Prime";
}
