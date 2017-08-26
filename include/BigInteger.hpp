#include <vector>
#include <deque>
#include <numeric>
#include <limits>
#include <sstream>
#include <algorithm>

#include <iostream>


using digit_t = char;
using base_t = short;

base_t const base = 10;//std::numeric_limits<digit_t>::max() + 1;

class BigInteger;

BigInteger operator+(BigInteger const& a,
					  BigInteger const& b);

BigInteger operator*(BigInteger const& a,
		             BigInteger const& b);

std::ostream& operator<<(std::ostream& os, const BigInteger& bi);



class BigInteger
{
   std::vector<digit_t> digits;

   template<typename T>
   void addDigits(T x)
   {
		while (x) {
			digits.push_back(int(x % base));
			x /= base;
		}
   }

public:
   // Plus minus operators
   friend BigInteger operator+(BigInteger const&, BigInteger const&);
   friend BigInteger operator*(BigInteger const&, BigInteger const&);

   // Comparison operators
   friend bool operator==(BigInteger const&, BigInteger const&);
   friend bool operator>(BigInteger const&, BigInteger const&);
   friend bool operator>=(BigInteger const&, BigInteger const&);
   friend bool operator<(BigInteger const&, BigInteger const&);
   friend bool operator<=(BigInteger const&, BigInteger const&);

   // Ostream operators
   friend std::ostream& operator<<(std::ostream& os, BigInteger const&);
   int getNumDigits(){
	   int zeros = 0;
	   for (auto  i =  digits.rbegin(); i!=digits.rend(); i++){
		   if (*i == 0){zeros++;} else {break;}
	   }
	   return digits.size()-zeros;
   }

   BigInteger() { addDigits(0); }
   BigInteger(short x) { addDigits(x); }
   BigInteger(int x) { addDigits(x); }
   BigInteger(long long x) { addDigits(x); }

   BigInteger(BigInteger const& other) : digits(other.digits) {   }
   BigInteger(std::vector<digit_t> const& digits) : digits(digits) { }

   BigInteger& operator=(const BigInteger& other)
   {
	   if (this != &other){
		   this->digits = other.digits;
	   }
	   return *this;
   }

   std::string toString() const{
	   std::stringstream ss;
	   auto len = digits.size();
	   auto p = 1;

	   for (size_t i = 0; i < len; i++){
		   ss<<int(digits[len -i -1]);
	   }

	   return ss.str();
   }

};

BigInteger operator*(BigInteger const& a,
		             BigInteger const& b)
{


	auto len_a = a.digits.size();
	auto len_b = b.digits.size();

	auto grid = std::vector<std::vector<digit_t>>(len_b,
			std::vector<digit_t>(len_a+len_b, 0));

	for (size_t i = 0;i<len_b;i++){
		base_t r = 0;
		for (size_t j = 0;j<len_a;j++){
			auto prod = b.digits[i] * a.digits[j];
			grid[i][j+i] = (prod + r) % base;
			r = (prod+r) / base;
		}
		if (r!=0){
			grid[i][len_a+i] = r;
		}
	}

	BigInteger out(grid[0]);
	for (size_t i = 1;i<len_b; i++){
		out = out + BigInteger(grid[i]);
	}

	return BigInteger(out);
}

BigInteger operator+(BigInteger const& a,
					  BigInteger const&b)
{
	auto out = BigInteger();
	auto len_a = a.digits.size();
	auto len_b = b.digits.size();

	size_t len = std::max(len_a, len_b);
	auto r = 0;

	for (size_t i = 0; i < len;i++){
		auto ai = (i<len_a ? a.digits[i] : 0);
		auto bi = (i<len_b ? b.digits[i] : 0);

		auto s = (ai + bi + r) % base;
		r = (ai+bi +r) / base;

		out.digits.push_back( s );
	}

	if (r != 0){
		out.digits.push_back(r);
	}

	return out;

}


std::ostream& operator<<(std::ostream& os, const BigInteger& bi)
{
    os << bi.toString();
    return os;
}

BigInteger pow(BigInteger const& base, const int exp){
	BigInteger out(1);
	for (int i = 0;i<exp; i++){
		out = out * base;
	}
	return out;
}

