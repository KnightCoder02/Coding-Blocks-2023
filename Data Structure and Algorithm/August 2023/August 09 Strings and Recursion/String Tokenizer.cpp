#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[] = "Hello...#World???...#$Learning,,,###...Strings..!";
    
    char *x = strtok(a, ".#?$,!"); //Fetch the words amongst random characters 
    // strtok(array name, array of delimiter);
    cout << x << endl; //Print Hello
    
    // // If you want to continue to check the array and fetch next words ahead of previous word then type NULL instead of array name 
    // x = strtok(NULL, ".#?$,!");
    // cout << x << endl; //Print World
    
    // x = strtok(NULL, ".#?$,!");
    // cout << x << endl; //Print Learning
    
    // x = strtok(NULL, ".#?$,!");
    // cout << x << endl; //Print Strings

    //Storing of words in a array
    string str[100];
    int n = 0;
    while(x != NULL){
        str[n++] = x;
        cout << x << endl; //Print Hello, World, Learning, Strings
        x = strtok(NULL, ".#?$,!");
    }

    cout << "------------------------------\n";
    for(int i = 0; i < n; i++){
        cout << str[i] << endl;
    }
}