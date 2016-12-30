#include <iostream>

int fibo();
int fibo2();
using namespace std;

int main(){
    cout<<fibo2()<<endl;
    return 0;
}

int fibo2(){
    int a,b,c,sum;
    sum=0;
    a=0;
    b=2;
    while (b< 4e6){
	c=4*b+a;
	a=b;
	b=c;
	sum+=a;
    }
    return sum;
}


int fibo(){
    int a,b,c,sum;

    a = b = 1;
    sum=0;

    while (b<4000000){
	if (b % 2 ==0) sum+=b;
	c = a+b;
	a=b;
	b=c;
    }

    return sum;
}
