#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

// 0.123456789101121314151617181922122232425262728293031...
// ans = d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000
int ans = 1;
int digit_counter = 1;
bool needsUpdate(int d){
    return (d==10 | d==100 | d==1000 | d==10000 | d==100000 | d==1000000);
}

void updateCounterAndAns(int n){
    deque<int> digits;
    while (n){
        digits.push_front(n%10);
        n /= 10;
    }

    for (auto d : digits){
        if (needsUpdate(digit_counter)){
            ans *= d;
        }
        digit_counter++;
    }
}
int main()
{
    for (int i = 1; i <= 1e6; i++){
        updateCounterAndAns(i);
        if (digit_counter > 1e6) break;
    }
    cout<<ans<<endl;

}
