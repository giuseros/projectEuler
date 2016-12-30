#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


vector<int> prime(int);

int main(){
 
    vector<int> p = prime(20);
    int mult, n, k, tmp;

    n=20;
    mult=1;
    for (vector<int>::iterator i = p.begin(); i<p.end();i++){
	k = floor( log(n) / log(*i));
	mult*=pow(*i,k);
    }

    cout<<mult<<endl;
    return 0;


}

vector<int> prime(int limit){
    vector<int> p;
    int i,j;

    for ( i = 2; i < limit; i++ ) {

	for ( j = 2; j <= i/2; j++ ) {

	    if (  i % j == 0 ) break;

	}
 
	if ( j > i / 2 ) p.push_back(i);
    }
    return p;
}
