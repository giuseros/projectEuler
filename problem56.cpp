#include <BigInteger.hpp>
#include <iostream>

using namespace std;
using long_t = long long int;

long_t getDigitSum(string const& num)
{
	long_t acc = 0;
	for (auto c : num){
		acc += (c-'0');
	}
	return acc;
}

int main()
{
	long_t maxSum = 0;
	for (int a = 1; a<100; a++){
		for (int b = 1; b< 100; b++){
			auto bi = pow(BigInteger(a), b);
			auto s = bi.toString();
			auto digitSum = getDigitSum(s);
			if (digitSum>maxSum){
				maxSum = digitSum;
			}
		}
	}


	cout<<maxSum<<endl;
	return 0;
}
