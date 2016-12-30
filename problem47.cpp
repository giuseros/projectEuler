#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define N 1e6
vector<bool> isPrime(N+1,true);
vector<int> primes;

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

void createPrimes()
{
    for (size_t i = 1; i<=N; i++){
        if (isPrime[i]) primes.push_back(i); 
    }
}

int getNumDistinctPrimes(int i)
{
    int p = 1;
    map<int,bool> divides;
    int count = 0;
    while (i != 1){
        if (i % primes[p] == 0){
            i /= primes[p];
            if(!divides[primes[p]]){ 
                count++; 
                divides[primes[p]] = true;
            }
        }else{
            p++;
            if (p>=primes.size()) {cout<<"error"<<endl;exit(0);}
        }
    }
    return count;
}

int main()
{
    sieve();
    createPrimes();
    int i = 100;
    int ans = 0;
    while(true){
        if (getNumDistinctPrimes(i) == 4 &&
            getNumDistinctPrimes(i+1) == 4 &&
            getNumDistinctPrimes(i+2) == 4 &&
            getNumDistinctPrimes(i+3) == 4){
            ans = i;
            break;
        }
        i++;
    }
    cout<<ans<<endl;
}
