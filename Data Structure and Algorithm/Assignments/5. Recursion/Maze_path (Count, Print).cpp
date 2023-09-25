#include <iostream>
using namespace std;

class MyClass{
    private:
    int count;

    public:
    MyClass(){
        count = 0;
    }

    void move(int r, int c, int cr, int cc, string direction){
        if(cr >= r || cc >= c){
            return;
        }

        if(cr == r - 1 && cc == c - 1){
            cout << direction << " ";
            count++;
            return;
        }

        move(r, c, cr + 1, cc, direction + 'V');
        move(r, c, cr, cc + 1, direction + 'H');
    }

    void printCount(){
        cout << endl << count << endl;
    }
};

int main(){
    int r, c;
    cin >> r >> c;

    MyClass o;
    o.move(r, c, 0, 0, "");
    o.printCount();
}