#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

vector<int> num;
unsigned long long ans;
vector<int> primes = {2,3,5,7,11,13,17,19};
bool checkProperty(vector<int> const& num)
{
    if (num[0] == 0) return false;

    int p = 0;
    for(int i = 1; i<8; i++){
        auto test = num[i]*100 + num[i+1]*10 + num[i+2];
        if (test % primes[p] != 0) return false;
        p++;
    }
    return true;
}

unsigned long long decode(vector<int> const& vnum){
    auto p = pow(10,vnum.size()-1);
    unsigned long long acc = 0;

    for (auto d:vnum){
        acc+= d*p;
        p/=10;

    }
    return acc;
}

#define N 10
map<int,bool> used;

void checkPandigital()
{
    if (num.size()==size_t(N)){
        if(checkProperty(num)){
            for(auto d : num){cout<<d;}
            cout<<endl;
            ans += decode(num);
        }
    }
    for (int i = 0;i < 10;i++){
        if (used[i] == false){
            used[i] = true;
            num.push_back(i);
            checkPandigital();
            num.pop_back();
            used[i] = false;
        }
    }
}

int main(){

    checkPandigital();
    cout<<ans<<endl;
    return 0;
}
