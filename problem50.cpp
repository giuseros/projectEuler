#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_first_primes(int);
void print_vector(vector<int>);
#define K 100

int main(){
    vector<int> primes=get_first_primes(K);
    int acc = 0,
	max_sum = 0;;

    print_vector(primes);
    for (vector<int>::iterator i = primes.begin();i!=primes.end();i++){
	if (find(i, primes.end(),acc+*i)!=primes.end())
	    acc+=*i;

    }

    cout<<acc<<endl;



    return 0;
}


vector<int> get_first_primes(int N){
    vector<int> primes;
    primes.push_back(2);

    for (int i = 3; i <= N;i+=2){

	bool prime = true;

	for (int j = 2; j < (i>>1); j++){
	    if ( i % j ==0){
		prime = false;
		break;
	    }
	}

	if (prime)
	    primes.push_back(i);
    }
    return primes;

}

void print_vector(vector<int> v){
    for (vector<int>::iterator  i = v.begin(); i != v.end();i++)
	cout<<*i<<" ";
    cout<<endl;
}
