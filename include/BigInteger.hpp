#include <limits>
#include <vector>

class BigInteger
{
    using digit_t = int32_t;
    std::vector<digit_t> digits;
public:
    BigInteger(int n)
    {
        if (n<std::numeric_limits<digit_t>){
            digits.push_back(n);
        }
    }

};
