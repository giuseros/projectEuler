#include <iostream>
#include <cmath>
#include <vector>
#include <map>

#define N 1e6
using namespace std;
vector<bool> isPrime(N+1, true);

void sieve()
{
    for (int i = 2; i<sqrt(N); i++){
        if (!isPrime[i]) continue;
        for (int j = i*i; j<=N;j+=i){
            isPrime[j] = false;
        }
    }
}

bool isflint(double x){
    return ceil(x) == x;
}

bool isSquare(int x)
{
    auto s = sqrt(double(x)*0.5);
    if (isflint(s)) return true;
    return false;
}

bool writeAsPrimeSum(int n)
{
    if (isPrime[n]) return true;
    for (int i = 2; i<=n-2;i++){
        if (!isPrime[i]){
            continue;
        }
        if (isSquare(n-i)){
            return true;
        }
    }
    return false;
}

int main()
{
    sieve();
    int n = 9;
    while(true){
        if (!writeAsPrimeSum(n)){
            break;
        }
        n+=2;
    }
    cout<<n<<endl;

}
