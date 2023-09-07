#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
bool compareStrings(const string &a, const string &b){
    return a + b > b + a;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        sort(numbers.begin(), numbers.end(), compareStrings);

        for(const std::string &num : numbers){
            cout << num;
        }
        cout << endl;
    }
}