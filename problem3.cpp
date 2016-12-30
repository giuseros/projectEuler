#include <iostream>
using namespace std;

int main(){
    int N=100;
    int sum =0;
    int sum2 = 0;

    for (int i =0;i<=100;i++)
	sum2+=i*i;


    sum=N*(N-1)/2;
    cout<<sum*sum - sum2<<endl;


    return 0;
}
