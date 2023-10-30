#include<iostream>
using namespace std;
template<typename t1, typename t2>
class Pair{
    public:
    t1 x;
    t2 y;
};

int main(){
    pair<int, int> p;   
    p.first = 10;
    p.second = 30;
    cout << p.first << ", " << p.second << endl;

    pair<int, string> p1;
    p1.first = 100;
    p1.second = "Hello";
    cout << p1.first << ", " << p1.second << endl;

    Pair<int, string> p2;
    p2.x = 11;
    p2.y = "World";
    cout << p2.x << ", " << p2.y;
}