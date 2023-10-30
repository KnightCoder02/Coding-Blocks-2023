#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> inputList(n);
    for(int i = 0; i < n; i++){
        cin >> inputList[i];
    }

    vector<int> oddElements;
    vector<int> evenElements;

    for(int i = 0; i < n; i++){
        if(inputList[i] % 2 == 1){
            oddElements.push_back(inputList[i]);
        }
        else{
            evenElements.push_back(inputList[i]);
        }
    }

    oddElements.insert(oddElements.end(), evenElements.begin(), evenElements.end());

    for(int i = 0; i < n; i++){
        cout << oddElements[i] << " ";
    }
}