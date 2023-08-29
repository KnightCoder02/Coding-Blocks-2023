#include<iostream>
#include<cstring>
using namespace std;
char maxFreq(char* str){
	int count[256] = {0};
	int len = strlen(str), max = 0;
	char result;

	for(int i = 0; i < len; i++){
		count[str[i]]++;
		if(max < count[str[i]]){
			max = count[str[i]];
			result = str[i];
		}
	}
	return result;
}

int main(){
	char str[1000] = "";
	cin >> str;
	cout << maxFreq(str);
}