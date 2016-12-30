#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
using long_t = unsigned long long;

vector<long_t> pentagonals;

void generatePentagonals(int N)
{
    for (long_t i = 0; i <= N;i++){
        int p = i*(3*i-1)/2;
        pentagonals.push_back(p);
    }
}
bool isflint(double x)
{
    if (ceil(x) == x)
        return true;
    return false;
}

bool isPentagonal(long_t n){
    double x1 = (1+sqrt(1+24*n))/6;
    double x2 = (1+sqrt(1-24*n))/6;
    if ( (x1 >= 0 && isflint(x1)) || (x2 >=0 && isflint(x2))){
        return true;
    }
    return false;
}

int main()
{
    int N = 10000;
    generatePentagonals(N);
    long_t min_diff(std::numeric_limits<long_t>::max());
    for (int i = 1; i<N;i++){
        for (int j = i+1; j<N;j++){
            auto sum = pentagonals[j] + pentagonals[i];
            auto diff = pentagonals[j] - pentagonals[i];
            if (isPentagonal(sum) && isPentagonal(diff)){
                min_diff = diff;
                cout<<pentagonals[i]<<endl;
                cout<<pentagonals[j]<<endl;
            }
        }
    }
    cout<<min_diff<<endl;
}
