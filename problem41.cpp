#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

#define N 987654321

vector<int> vnum; 
map<int,bool> used;

int max_panprime(0);

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

int decode(vector<int> const& vnum){
    auto p = pow(10,vnum.size()-1);
    int acc = 0;

    for (auto d:vnum){
        acc+= d*p;
        p/=10;

    }
    return acc;
}

void checkPandigital(int targetNumDigits)
{
    if (vnum.size()==targetNumDigits){
        auto num = decode(vnum);
        if (isPrime[num] && num > max_panprime){
            max_panprime = num;
        }
    }

    for (int i = 1;i<=targetNumDigits;i++){
        if (!used[i]){
            used[i] = true;
            vnum.push_back(i);
            checkPandigital(targetNumDigits);
            vnum.pop_back();
            used[i] = false;
        }
    }
}

// 123456789
// 100000000
int main()
{
    sieve();
    checkPandigital(7);
    cout<<max_panprime<<endl;
    return 0;
}
