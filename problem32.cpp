#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_set>

#include <algorithm>
using long_t = long;

using namespace std;
int const N = 9;

long_t cc(0);

// {1,2,3,4} -> 1234
int vec2num(vector<int> const& vec, int start, int end){
	int p = pow(10, end - start -1);
	int acc(0);
	for (int i = start;i<end;i++){
		acc += p*vec[i];
		p /= 10;
	}
	return acc;
}

/*
 * 1*2=345*6789
 */

unordered_set<int> cache;

long_t countUnusual(vector<int> const& perm){
	long_t local_cc(0);

	for (long_t starPos = 1;starPos<=N-2;starPos++){
		for (long_t eqPos = starPos+1; eqPos <=N-1 ;eqPos++){
			auto p1 = vec2num(perm, 0, starPos);
			auto p2 = vec2num(perm, starPos, eqPos);
			auto r = vec2num(perm, eqPos, N);
			if (p1==0 || p2==0 || r==0) cout<<"error"<<endl;
			if (p1*p2==r && cache.find(r)==cache.end() ){
				local_cc++;
				cache.insert(r);
			}
		}
	}
	return local_cc;
}



void backtrace(vector<int> perm){
	if (perm.size()==size_t(N)){
		cc += countUnusual(perm);
	}

	for(int i = 1;i<=9;i++){
		if (find(perm.begin(), perm.end(), i)==perm.end()){
			perm.push_back(i);
			backtrace(perm);
			perm.pop_back();
		}
	}
}


int main(){
	backtrace(vector<int>());
	auto ans(0);
	for (auto &s : cache){
		ans += s;
		cout<<s<<endl;
	}
//	cout<<countUnusual({3,9,1,8,6,7,2,5,4})<<endl;
	cout<<"ans: "<<ans<<endl;
}
