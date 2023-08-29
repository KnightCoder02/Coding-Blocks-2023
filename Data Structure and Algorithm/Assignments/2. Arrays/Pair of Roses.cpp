#include<iostream>
#include<climits>
using namespace std;
int main(){
	int price[100000], T;
	cin >> T;

	for(int t = 0; t < T; t++){
		int n;
		cin >> n;

		for(int i = 0; i < n; i++){
			cin >> price[i];
		}

		int money;
		cin >> money;
		int min_diff = INT_MAX, fr = -1, sr = -1;
		
		for(int i = 0; i < n; i++){
			int first_rose = price[i], req_price = money - first_rose;
			for(int j = 0; j < n; j++){
				if(j != i){
					if(price[j] == req_price){
						int curr_diff = first_rose - price[j];
						if(curr_diff < 0){
							curr_diff = -1 * curr_diff;
						}

						if(curr_diff < min_diff){
							min_diff = curr_diff;
							fr = first_rose;
							sr = price[j];
						}
					}
				}
			}
		}

		if(fr > sr){
			swap(fr, sr);
		}

		cout << "Deepak should buy roses whose prices are " << fr << " and " << sr << "." << endl;
	}
}