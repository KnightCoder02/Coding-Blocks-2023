#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int findPaths(int N1, int N2, string path, vector<string> &allPaths){
    if(N1 == 1 && N2 == 1){
        allPaths.push_back(path);
        return 1;
    }

    int count = 0;
    if(N1 > 1){
        count += findPaths(N1 - 1, N2, path + "V", allPaths);
    }

    if(N2 > 1){
        count += findPaths(N1, N2 - 1, path + "H", allPaths);
    }

    if(N1 > 1 && N2 > 1){
        count += findPaths(N1 - 1, N2 - 1, path + "D", allPaths);
    }

    return count;
}

int main(){
    int N1, N2;
    cin >> N1 >> N2;

    vector<string> allPaths;
    int totalPaths = findPaths(N1, N2, "", allPaths);

    for(const string& path : allPaths){
        cout << path << " ";
    }

    cout << "\n" << totalPaths << endl;
}