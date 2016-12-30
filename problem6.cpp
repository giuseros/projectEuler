#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
bool check_palindrome(int x);
vector<int> get_digit(int x);

int main(){
    int max=0;
    for (int i = 100;i<999;i++){
        for (int j = 100;j<999;j++){
            if ( check_palindrome(i*j) && i*j>max)
		max=i*j;
        }
    }
    cout<<max<<endl;
    return 0;
}
bool check_palindrome(int x){
    vector<int> digits = get_digit(x);
//    for (int i =0;i<digits.size();i++)
//	cout<<digits[i]<<endl;
    bool p = true;
    for (int i = 0;i<int(digits.size()/2);i++)
	if (digits[i]!=digits[(digits.size()-1)-i])
		p = false;
    
    return p;
}

vector<int> get_digit(int x){
    vector<int> digits;
    while (x>0){
	digits.push_back(x%10);
	x/=10;
    }
    return digits;
}



