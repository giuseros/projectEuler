#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

//std::vector<int> primes = {2,3,5,7,9,11,13,17,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};

vector<int>primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
using Representation = vector<pair<int,int>>;

vector<pair<int,int>> decompose(int n, int k){
	vector<pair<int,int> > rep;
	for (auto &p : primes){
		int c = 0;
		while (n%p==0){
			c++;
			n /= p;
		}
		if (c != 0){
			rep.push_back(make_pair(p,c*k));
		}
	}
	sort(rep.begin(), rep.end(), [](pair<int,int> a, pair<int,int> b){
		return (a.first < b.first || (a.first == b.first && a.second < b.second));

	});
	return rep;
}

int main(){
	int newcomers(0);
	set<Representation> reps;
	for (int i = 2;i<=100;i++){
		for (int j = 2; j<=100;j++){
			auto representation = decompose(i,j);
			if (reps.find(representation) == reps.end()){
				newcomers++;
				reps.insert(representation);
			}
		}
	}
	cout<<newcomers<<endl;
}
