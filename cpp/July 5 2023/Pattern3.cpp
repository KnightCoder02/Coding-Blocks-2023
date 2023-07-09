/*
1
2 3
4 5 6
7 8 9 10
*/

/*
#include<iostream>
using namespace std;
int main(){
    int n, row = 1, i, no = 1;
    cin >> n;

    while(row <= n){
        i = 1;
        while(i <= row){
            cout << no << " ";
            no = no + 1;
            i = i + 1;
        }
        cout << endl;
        row = row + 1;
    }
}
*/

#include<iostream>
using namespace std;
int main(){
	int n, no = 1;
	cin >> n;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cout << no << " ";
            no = no + 1;
		}
		cout << "\n";
	}
}