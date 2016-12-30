#include <iostream>
#include <cmath>
using long_t = unsigned long long;
using namespace std;

long_t getTriangular(long_t i)
{
    return i*(i+1)/2;
}

bool isflint(double x)
{
    if (ceil(x) == x)
        return true;
    return false;
}

bool isPentagonal(double n)
{
    double x1 = (1+sqrt(1+24*n))/6;
    double x2 = (1+sqrt(1-24*n))/6;
    if ( (x1 >= 0 && isflint(x1)) || (x2 >=0 && isflint(x2))){
        return true;
    }
    return false;
}

bool isExagonal(double n)
{
    double x1 = (1+sqrt(1+8*n))/4;
    double x2 = (1+sqrt(1-8*n))/4;
    if ( (x1 >= 0 && isflint(x1)) || (x2 >=0 && isflint(x2))){
        return true;
    }
    return false;
}

int main()
{
    long_t i = 286;
    long_t x = getTriangular(i);
    while (!isPentagonal(x) || !isExagonal(x)){
        x = getTriangular(i);
        i++;
    }
    cout<<x<<endl;
}
