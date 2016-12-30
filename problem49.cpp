#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define N 1e6
vector<bool> isPrime(N+1,true);
vector<int> perms;

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

void generatePerms()
{
}


int main()
{
    return 0;
}
