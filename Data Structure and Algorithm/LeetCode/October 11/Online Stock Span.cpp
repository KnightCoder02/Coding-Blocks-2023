#include<iostream>
#include<stack>
using namespace std;
class Pair{
    public:
    int price;
    int span;
};

class StockSpanner{
    public:
    stack<Pair> s;
    StockSpanner(){

    }

    int next(int price){
        int span = 1;
        while(!s.empty() && s.top().price <= price){
            span += s.top().span;
            s.pop();
        }

        s.push({price, span});
        return span;
    }
};

int main(){}