#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string alphabet = "bcdefghijklmnopqrstuvwxyza";


bool isValidLetter(char letter)
{
	bool const isValid = (letter >= 'a' && letter <='z' ||
			              letter >= 'A' && letter <= 'Z' ||
						  letter >= '0' && letter <= '9' ||
						  letter == ' ' || letter == ',' ||
						  letter == '.' || letter == ';' ||
						  letter == ')' || letter == '(' ||
						  letter == '!' || letter == '?' ||
						  letter == '\'');
	return isValid;
}

int decode(string const& message, string const& key)
{
	long  sum(0);
	auto keyLength = key.length();
	for (int i = 0; i<message.length(); i++){
		char decodedLetter = char(message[i] ^ key[i % keyLength]);
		if (isValidLetter(decodedLetter)){
				sum += int(decodedLetter);
		} else {
			return -1;
		}
	}
	return sum;
}

int main(){
	auto message = string();
	ifstream s;
	s.open("/local/projects/projectEuler/p059_cipher.txt" , ios_base::in);
	auto num = string();

	while (!s.eof()){
		char x;

		s>>x;
		if (x!=','){
			num.push_back(x);
		}
		if (x==',' ) {
			message.push_back(char(std::stoi(num)));
			num.clear();
		}

	}

	num.pop_back();
	message.push_back(char(std::stoi(num)));
	s.close();

	auto key = string("xxx");
	for (int i = 0; i < alphabet.length(); i++){
		for (int j = 0; j < alphabet.length(); j++){
			for (int k = 0; k < alphabet.length(); k++){
				key[0] = alphabet[i];
				key[1] = alphabet[j];
				key[2] = alphabet[k];
				int sum = decode(message, key);
				if (sum!= -1){
					cout<<key<<":"<<sum<<endl;
				}
			}
		}
	}



	return 0;
}
