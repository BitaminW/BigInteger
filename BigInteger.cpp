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


BigInteger::~BigInteger() {

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

int BigInteger::operator[](const int index)const {
	// 인덱스 범위 밖으로 접근하거나 인덱스가 0일 경우 에러 발생
	if (m_value.size() <= index || index < 0)
		throw("ERROR");
	return m_value[index];
}

bool operator==(const BigInteger& left, const BigInteger& right) {
	return left.m_value == right.m_value;
}

bool operator!=(const BigInteger& left, const BigInteger& right) {
	return !(left.m_value == right.m_value);
}

bool operator<(const BigInteger& left, const BigInteger& right) {
	int temp1 = Length(left), temp2 = Length(right);
	// 길이가 같지 않다면 그대로 left < right 리턴
	if (temp1 != temp2) 
		return temp1 < temp2;
	while (temp1--) {
		if (left.m_value[temp1] != right.m_value[temp2])
			return left.m_value[temp1] < right.m_value[temp2];
	}
	return false;
}

bool operator>(const BigInteger& left, const BigInteger& right) {
	return right < left;
}

bool operator>=(const BigInteger& left, const BigInteger& right) {
	return !(left < right);
}

bool operator<=(const BigInteger& left, const BigInteger& right) {
	return !(left > right);
}

BigInteger& BigInteger::operator=(const BigInteger& right) {
	m_value = right.m_value;
	return *this;
}

BigInteger& BigInteger::operator++() {
	int i, length = m_value.size();
	for (i = 0; i < length && m_value[i] == 9; i++) 
		m_value[i] = 0;
	
	if (i == length)
		m_value.push_back(1);
	else
		m_value[i]++;
	
	return *this;
}

//BigInteger BigInteger::operator++(int temp) {
//	BigInteger aux;
//	aux = *this;
//	++(*this);
//	return aux;
//}


/// <summary>
/// TODO ::
/// </summary>
/// <returns></returns>
//BigInteger& BigInteger::operator--() {
//	if (m_value[0] == 0 && m_value.size() == 1)
//		throw("UNDERFLOW");
//	int i, length = m_value.size();
//	
//	for (i = 0; m_value[i] == 0 && i < length; i++)
//		m_value[i] = 9;
//	
//	m_value[i]--;
//	if (length > 1 && m_value[length - 1] == 0)
//		m_value.pop_back();
//	
//	return *this;
//}

