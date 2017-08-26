#include <iostream>

template <typename intType>
intType countDigits(intType n){
	intType numDigits(0);
	while(n){
		numDigits++;
		n /= 10;
	}
	return numDigits;
}

std::ostream& operator<<(std::ostream& out, std::vector<int> const& vector)
{
	for (auto const& elem : vector){
		out<<elem<<" ";
	}
	return out;
}
