#include <iostream>
#include <vector>

using namespace std;

int reverseAndAdd(int n)
{
	return 0;
}

bool isPalindrome(int n){
	return true;
}

int main()
{
	int count(0);
	for (int i = 0;i<=10000;i++){
		int n = i;
		for (int k = 0;i<50;k++){
			n = reverseAndAdd(n);
			if (isPalindrome(n)){
				count++;
				break;
			}
		}
	}
	cout<<count<<endl;
}
