#include <iostream>
#include <vector>

using namespace std;

vector<int> decode(int i){
	vector<int> digits;
	while (i){
		digits.push_back(i % 10);
		i /= 10;
	}
	return digits;
}

bool compareWithFiftPower(vector<int> const& digits, int const & n){
	int acc(0);
	for (auto &d : digits){
		acc += d*d*d*d*d;
	}
	return (acc==n);
}

int main(){
	int sum(0);
	for(int i = 2; i <= 999999; i++){
		auto digits = decode(i);
		if (compareWithFiftPower(digits, i)){
			sum += i;
		}
	}
	cout<<sum<<endl;
}
