#include "BigInteger.h"




BigInteger::BigInteger(ull number){
	do {
		m_value.push_back(number % 10);
		number /= 10;
	} while (number);
}

BigInteger::BigInteger(std::string& str){
	m_value = "";
	int str_length = str.size();
	
	for (int i = str_length - 1; i >= 0; i--) {
		if (!isdigit(str[i]))
			throw("ERROR");
		m_value.push_back(str[i] - '0');
	}
}

BigInteger::BigInteger(const char* s) {
	m_value = "";

	for (int i = strlen(s) - 1; i >= 0; i--) {
		if (!isdigit(s[i]))
			throw("ERROR");
		m_value.push_back(s[i] - '0');
	}
}

BigInteger::BigInteger(BigInteger& ref_BigInteger) {
	m_value = ref_BigInteger.m_value;
}


/*
	a collection of helper functions definitions
*/

bool Null(const BigInteger& ref_BigInteger) {
	if (ref_BigInteger.m_value.size() == 1 && ref_BigInteger.m_value[0] == 0) {
		return true;
	}
	return false;
}

int Length(const BigInteger& ref_BigInteger) {
	return ref_BigInteger.m_value.size();
}




