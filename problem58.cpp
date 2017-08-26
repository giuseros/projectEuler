#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;

using long_t = unsigned long long int;
ErathostenePrimeDetector epd(1e9);

double calculatePercentagePrime(std::vector<long_t> const& diags)
{
	auto tot = diags.size();
	auto primes = 0;
	for (auto const& n : diags){
		if (epd.isPrime(n)){
			primes++;
		}
	}
	return double(primes) / double(tot);
	return 0;
}


int main(){
	long_t side = 3;
	long_t topLeft(5), topRight(3), bottomLeft(7), bottomRight(9);
	std::vector<long_t> diags{1,5,3,7,9};
	auto p = calculatePercentagePrime(diags);
	while(p > 0.1){

		topLeft += 4*side;
		topRight += 4*side-2;
		bottomLeft += 4*side+2;
		bottomRight += 4*(side+1);

		diags.push_back(topLeft);
		diags.push_back(topRight);
		diags.push_back(bottomRight);
		diags.push_back(bottomLeft);
		p = calculatePercentagePrime(diags);
		cout<<p<<endl;
		side+=2;
	}

	std::cout<<(diags.size()+1)/2<<std::endl;
	return 0;
}




