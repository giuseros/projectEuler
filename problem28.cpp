#include <iostream>
using namespace std;
using long_t = long long;

int main(){
	long_t N = 1001;

	long_t sum = 1;
	for (long_t i = 1;i<N;i+=2){
//		cout<<"i:"<<i<<endl;
		long_t start = i*i+i+1;
		long_t end = (i+2)*(i+2);
		long_t step = i+1;
		for (long_t j = start; j<=end; j+=step){
			sum+=j;
			//cout<<"j:"<<j<<endl;
		}
	}
	cout<<sum<<endl;
}
