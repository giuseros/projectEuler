#include <iostream>
#include <cmath>

using namespace std;

long mysolution(long);
long opsolution(long);
long gcd (long, long);

int main(){
    long s = 100000;
    cout<<opsolution(s)<<endl;;
    return 0;
}


long mysolution(long sum){
    long prod;

    for (long a = 3;a<(sum-3)/3;a++){
	for (long b = a+1;b<(sum-1-a)/2;b++){
	    long c = sum-a-b;
	    if (c*c == a*a + b*b){
		//cout<<a<<"+"<<b<<"+"<<c<<endl;
		prod = a*b*c;
		return prod;
	    }

	}
    }

}

long opsolution (long sum){
    //long s2, sm, k, d,m,n,a,b,c, mlimit;
    long a,b,c,
	 m,n,
	 k,d,
	 s2,sm,mlimit;

    s2 = sum / 2;
    mlimit = ceil(sqrt(s2))-1;
    for (long m = 2; m <= mlimit; m++){
	if (s2 % m == 0){
	    sm = s2 / m;

	    //We are finding an odd divisor of sm, thus all even factor c may
	    //be removed
	    while (sm % 2 == 0)
		sm = sm/2;

	    //k must be odd
	    if (m %2 == 1)
		k = m+2;
	    else
		k=m+1;

	    while (k<2*m && k<=sm){
		if (sm %k ==0 && gcd (k,m)==1){
		    d=s2/(k*m);
		    n=k-m;
		    a= d*(m*m -n*n);
		    b = 2*d*m*n;
		    c = d*(m*m+n*n);
		    return a*b*c;
		}
		k+=2;
	    }
	}
    }
}

long gcd(long a, long b){
    if (b==0)
	return a;
    else
	return gcd(b,a%b);
}
