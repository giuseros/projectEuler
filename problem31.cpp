#include <iostream>
#include <vector>
using namespace std;
using long_t = long long;

vector<long_t>  coins = {1, 2, 5, 10, 20, 50, 100, 200};
long_t const target = 200;
long_t counts(0);

void solve(vector<long_t> set, long_t value){
	if (value == 0){
		counts++;
		return;
	}

	for (int i = set.size() -1; i>=0;i--){

		long_t c  = set[i];
		if (c > value) continue;
		solve(set, value -c);
		set.erase(set.begin() + i);

	}
}

int main(){
	solve(coins, 200);
	cout<<counts<<endl;


}
