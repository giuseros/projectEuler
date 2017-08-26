#include <iostream>
#include <vector>
#include "utils.hpp"
#include "BigInteger.hpp"

using namespace std;

using long_t = unsigned long long;

int main(){
	int count = 0;
	BigInteger numerator(3), denominator(2);
	for (int i = 1; i<=1000; i++){
		if (numerator.getNumDigits() > denominator.getNumDigits()){
			count++;
		}
		auto tmpNum = numerator;
		auto tmpDen = denominator;
		denominator = tmpNum + tmpDen;
		numerator = 2*tmpDen+tmpNum;
//		std::cout<<numerator<<"("<<numerator.getNumDigits()<<")"<<std::endl;
	}
	std::cout<<count<<endl;




	return 0;
}
