#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using long_t = unsigned long long;
long_t reverse(long_t n)
{
	long_t t(n), r(0);
//	cout<<n<<endl;
	while(t){
		r = r*10 + t%10;
		t /= 10;
	}
//	cout<<r<<endl;
	return r;
}

long_t reverseAndAdd(long_t n)
{
	return n+reverse(n);
}

bool isPalindrome(long_t n){
	return reverse(n) == n;
}

int main()
{
	int count(0);

	for (int i = 196;i<1e4;i++){
		long_t n = i;
		bool isLychrel(true);

		for (int k = 0;k<50;k++){
			n = reverseAndAdd(n);
			if (isPalindrome(n)){
				isLychrel = false;
				break;
			}
		}
		if (isLychrel){
			count++;
		}
	}
	cout<<count<<endl;
}
