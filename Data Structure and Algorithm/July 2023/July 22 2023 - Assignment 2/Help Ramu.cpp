#include<iostream>
using namespace std;

int c1, c2, c3, c4;
int no_rick, no_cab;
int ride_rick[10000], ride_cab[10000];

int cost(){
    //For Rickshaw
    int cost_rick = 0;
    for(int i = 0; i < no_rick; i++){
        
        //2 options for rickshaw
        // 1. Pay for single ride --> ride_rick[i]*c1;
        int op1 = ride_rick[i]*c1;

        // 2. Hire rickshaw for monthly basis --> c2;
        int op2 = c2;

        cost_rick += min(op1, op2);
    }

    //Unlimited rides on all rickshaw --> c3
    cost_rick = min(cost_rick, c3);

    //For cab
    int cost_cab = 0;
    for(int i = 0; i < no_cab; i++){
        
        //2 options for cab
        // 1. Pay for single ride --> ride_cab[i]*c1;
        int op1 = ride_cab[i]*c1;

        // 2. Hire cab for monthly basis --> c2;
        int op2 = c2;

        cost_cab += min(op1, op2);
    }

    //Unlimited rides on all cab --> c3
    cost_cab = min(cost_cab, c3);

    int total_cost = cost_rick + cost_cab;

    //Unlimited rides on all rickshaw and cabs
    total_cost = min(total_cost, c4);
    return total_cost;
}

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> c1 >> c2 >> c3 >> c4;
        cin >> no_rick >> no_cab;

        for(int i = 0; i < no_rick; i++){
            cin >> ride_rick[i];
        }

        for(int i = 0; i < no_cab; i++){
            cin >> ride_cab[i];
        }
        cout << cost() << endl;
    }
}