#include<iostream>
using namespace std;

int largestNum(int num){
	string str = to_string(num);
	string temp = str;

	for (int i = 0; i < str.size(); i++) {
		for (int j = i + 1; j < str.size(); j++) {
			swap(str[i], str[j]);
			if (stoi(str) > stoi(temp))
				temp = str;
			swap(str[i], str[j]);
		}
	}
	return stoi(temp);
}

int main() {
	int num;
    cin >> num;
	cout << largestNum(num) << endl;
}