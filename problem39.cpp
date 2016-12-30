#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

bool isflint(double n){
    if (floor(n) == n){
        return true;
    } 
    return false;
}

int main(){
    unordered_map<int,int> p;
    for (int b = 1; b <= 1000; b++){
        for (int h = b; h<=1000;h++){
            double y = sqrt(double(b*b) + double(h*h));
            double t = double(b) + double(h) + y ;
            if (!isflint(t)) continue;
            if (t > 1000) continue;
            p[int(t)]++;
        }
    }
    cout<<p[120]<<endl;
    int ans = 0;
    int max = 0;
    for (auto const& ii : p){
        if (ii.second > max){
             max = ii.second;
             ans = ii.first;
        }
    }
    cout<<ans<<endl;

}
