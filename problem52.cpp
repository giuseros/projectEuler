#include <iostream>
#include <map>
#include <vector>

using namespace std;
using long_t = unsigned long long ;

vector<long_t> num2vec(long_t a)
{
	vector<long_t> digits;
	while (a){
		digits.push_back(a%10);
		a /= 10;
	}
	return digits;
}


bool checkNums(long_t x, long_t x2, long_t x3, long_t x4, long_t x5)
{

	map<long_t, bool> digits;

	auto v = num2vec(x);
	for ( auto d:v ){digits[d] = true;}

	auto v2 = num2vec(x2);
	auto v3 = num2vec(x3);
	auto v4 = num2vec(x4);
	auto v5 = num2vec(x5);

	for (auto d:v2){ if (!digits[d]) return false;}
	for (auto d:v3){ if (!digits[d]) return false;}
	for (auto d:v4){ if (!digits[d]) return false;}
	for (auto d:v5){ if (!digits[d]) return false;}



	return true;
}
int main()
{
	long_t x = 125874;

	while (true){
		long_t x2 = 2*x;
		long_t x3 = 3*x;
		long_t x4 = 4*x;
		long_t x5 = 5*x;

		if (checkNums(x,x2,x3,x4,x5)){
			cout<<x<<endl;
			break;
		}
		x++;
	}
}
