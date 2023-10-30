#include <iostream>
#include <stack>
using namespace std;

int findCelebrity(int n, int matrix[100][100]){
    stack<int> candidates;

    // Add all people as potential candidates.
    for(int i = 0; i < n; i++){
        candidates.push(i);
    }

    while(candidates.size() > 1){
        int a = candidates.top();
        candidates.pop();

        int b = candidates.top();
        candidates.pop();

        // If a knows b, a can't be the celebrity.
        if(matrix[a][b] == 1){
            candidates.push(b);
        }

        // If a doesn't know b, b can't be the celebrity.
        else{
            candidates.push(a);
        }
    }

    // Check if the remaining candidate is a celebrity.
    int potentialCelebrity = candidates.top();
    for(int i = 0; i < n; i++){
        if(i != potentialCelebrity && (matrix[i][potentialCelebrity] == 0 || matrix[potentialCelebrity][i] == 1)){
            // The remaining candidate does not know everyone or is known by someone else.
            return -1; // No celebrity found.
        }
    }

    return potentialCelebrity;
}

int main(){
    int n;
    cin >> n;

    int matrix[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    int celebrity = findCelebrity(n, matrix);

    if(celebrity != -1){
        cout << celebrity << endl;
    }
    else{
        cout << "No Celebrity" << endl;
    }
}
