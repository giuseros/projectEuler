#include <iostream>
#include <cmath>
#include <vector>
#include <map>


using namespace std;

#define N 1e6
vector<bool> isPrime(N+1,true);

void sieve()
{
    isPrime[1] = true;
    isPrime[2] = true;
    for (int i = 2; i <= sqrt(N);i++){
        for (int j = i*i; j<=N;j+=i){
            isPrime[j] = false;
        }
    }
}

vector<int> vectorize(int a){
	vector<int> digits;
	while (a){
		digits.push_back(a%10);
		a /= 10;
	}
	return digits;
}
bool verifyPerms(int a, int b, int c)
{
	map<int, bool> hist;

	auto digitsA = vectorize(a);
	auto digitsB = vectorize(b);
	auto digitsC = vectorize(c);

	if (digitsA.size() != digitsB.size() || digitsA.size() != digitsC.size() ||
			digitsB.size() != digitsC.size()) return false;

	for (auto d : digitsA){hist[d] = true;}
	for (auto d : digitsB){if (!hist[d]) return false;}
	for (auto d : digitsC){if (!hist[d]) return false;}

	return true;
}


bool verify(int a, int b, int c)
{
	bool allPrimes = isPrime[a] && isPrime[b] && isPrime[c];
	bool allPerms = verifyPerms(a,b,c);
	return allPrimes && allPerms;
}

int main()
{
	sieve();
	int x = 1488;
	int inc = 3330;

	while (true){
		int a = x;
		int b = a + inc;
		int c = b + inc;

		if (verify(a,b,c)){
			cout<<a<<"-"<<b<<"-"<<c;
			break;
		}
		x++;
	}
}
