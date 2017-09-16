#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>

#include "utils.hpp"

using namespace std;
size_t const N = 7000;
bool mem[N][N];

size_t getPten(size_t p){
	auto ret = 10;
	if (p>10) ret *= 10;
	if (p>100) ret *= 10;
	if (p>1000) ret *= 10;
	if (p>10000) ret *= 10;
	if (p>100000) ret *= 10;
	if (p>1000000) ret *= 10;
	if (p>10000000) ret *= 10;
	if (p>100000000) ret *= 10;
	if (p>1000000000) ret *= 10;

	return ret;
}

bool isPrime(size_t const n, std::vector<size_t> const& primes) {
  if (n == 2) return true;
  for (int i = 0; ; ++i) {
    int p = primes[i];
    if (p * p > n) return true;
    if (n / p * p == n) return false;
  }
  return true;
}

int main()
{

	auto primes = std::vector<size_t>();
	size_t i = 2;

	while(primes.size()<N){
		if (isPrime(i, primes)){
			primes.push_back(i);
		}
		i++;
	}
	cout<<"done generating primes"<<endl;
	for (size_t i = 0; i<N;i++){

		for (size_t j = 0; j < i; j++){
			auto p1 = primes[i];
			auto p2 = primes[j];

			auto pten1 = getPten(p1);
			auto pten2 = getPten(p2);

			auto pp1 = pten1*p2 + p1;
			auto pp2 = pten2*p1 + p2;

			if (!isPrime(pp1, primes) || !isPrime(pp2, primes))	{
				mem[i][j] = false;
			} else {
				mem[i][j] = true;
			}
		}

		for (size_t j = 0; j<i;j++){
			if (!mem[i][j]){ continue; }
			for (size_t k = 0; k < j;k++){
				if (!mem[i][k] || !mem[j][k] ){ continue; }
				for (size_t l = 0; l < k; l++){
					if (!mem[i][l] || !mem[j][l] || !mem[k][l]){ continue; }
					for(size_t m = 0; m<l; m++){
						if (!mem[i][m] || !mem[j][m] || !mem[k][m] || !mem[l][m]){ continue; }
						cout<<(std::vector<size_t>{primes[i], primes[j], primes[k], primes[l], primes[m]})<<endl;
					}
				}
			}
		}
	}
}
