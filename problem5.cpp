#include <iostream> 

using namespace std;

int main(){

    unsigned long n = 600851475143;
    unsigned long factor = 2;
    unsigned long lastFactor = 1;

    while ( n > 1){
	if (n % factor == 0){
	    lastFactor = factor;
	    n = n / factor;
	    while (n % factor==0)
		n = n / factor;
	}
	factor=factor+1;
    }
    cout<<lastFactor<<endl;
    return 0;
}

	    
//int main(){
//    unsigned long limit = 600851475143;
//    unsigned long tmp = limit;
//    unsigned long i,j;
//
//    for ( i = 2; i < limit/2; i++ ) {
//
//	for ( j = 2; j <= i/2; j++ ) {
//
//	    if (  i % j == 0 ) break;
//
//	}
// 
//	if ( j > i / 2 ) {
//	    while (tmp % i ==0)
//		tmp /= i;
//
//	    if (tmp ==1){
//		cout<<i<<endl;
//		break;
//	    }
//	}
//		
//    }
//    return 0;
//}
