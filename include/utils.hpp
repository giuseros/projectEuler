#ifndef PROJECTEULER_UTILS_HH
#define PROJECTEULER_UTILS_HH

#include <iostream>
#include <vector>
#include <cmath>

class ErathostenePrimeDetector
{
private:
	std::vector<bool> fIsPrime;
	size_t const fNumPrimes;
public:
	ErathostenePrimeDetector(size_t const N):
		fNumPrimes(N),
		fIsPrime(N+1,true)
	{
		fIsPrime[1] = false;
		fIsPrime[2] = true;
		for (int i = 2; i <= sqrt(N);i++){
			for (int j = i*i; j<=N;j+=i){
				fIsPrime[j] = false;
			}
		}
	}

	bool isPrime(size_t n){ return fIsPrime[n]; }
};

template <typename intType>
intType countDigits(intType n){
	intType numDigits(0);
	while(n){
		numDigits++;
		n /= 10;
	}
	return numDigits;
}

std::ostream& operator<<(std::ostream& out, std::vector<int> const& vector)
{
	for (auto const& elem : vector){
		out<<elem<<" ";
	}
	return out;
}

#endif
