#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void calculateStockSpans(const vector<int>& prices, vector<int>& spans){
    int n = prices.size();
    stack<int> st;
    spans.resize(n);

    for(int i = 0; i < n; i++){
        while(!st.empty() && prices[i] >= prices[st.top()]){
            st.pop();
        }

        if(st.empty()){
            spans[i] = i + 1;
        }
        else{
            spans[i] = i - st.top();
        }

        st.push(i);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    vector<int> spans;
    calculateStockSpans(prices, spans);

    for(int i = 0; i < n; i++){
        cout << spans[i] << " ";
    }

    cout << "END" << endl;
}
