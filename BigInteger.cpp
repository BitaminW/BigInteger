#include "BigInteger.h"

//		Constructor

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

/*

	*******	i 스코프 확인    *********
*/
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

BigInteger BigInteger::operator++(int temp) {
	BigInteger aux;
	aux = *this;
	++(*this);
	return aux;
}

BigInteger& BigInteger::operator--() {
	if (m_value[0] == 0 && m_value.size() == 1)
		throw("UNDERFLOW");
	int i, length = m_value.size();
	
	for (i = 0; m_value[i] == 0 && i < length; i++)
		m_value[i] = 9;
	
	m_value[i]--;
	if (length > 1 && m_value[length - 1] == 0)
		m_value.pop_back();
	
	return *this;
}

BigInteger BigInteger::operator--(int temp) {
	BigInteger aux;
	aux = *this;
	--(*this);
	return aux;
}

BigInteger &operator+=(BigInteger& left, const BigInteger& right) {
	int t = 0, s;
	int n = Length(left), m = Length(right);

	if (m > n) {
		left.m_value.append(m - n, 0);
	}
	n = Length(left);

	for (int i = 0; i < n; i++) {
		if (i < m)
			s = (left.m_value[i] + right.m_value[i]) + t;
		else
			s = left.m_value[i] + t;

		t = s / 10;
		left.m_value[i] = (s % 10);
	}
	if (t)
		left.m_value.push_back(t);

	return left;
}

BigInteger operator+(const BigInteger& a, const BigInteger& b) {
	BigInteger temp;
	temp = a;
	temp += b;
	return temp;
}

BigInteger &operator-=(BigInteger& left, const BigInteger& right) {
	if (left < right)
		throw("UNDERFLOW");

	int n = Length(left), m = Length(right);
	int s, t = 0;
	

	for (int i = 0; i < n; i++) {
		if (i < m)
			s = left.m_value[i] - right.m_value[i] + t;
		else
			s = left.m_value[i] + t;

		if (s < 0) {
			s += 10;
			t = -1;
		}
		else
			t = 0;

		left.m_value[i] = s;
	}

	// 0으로 채워져있는 앞 자리수를 줄여준다.
	while (n > 1 && left.m_value[n - 1] == 0) {
		left.m_value.pop_back();
		n--;
	}
	return left;
}


BigInteger operator-(const BigInteger& left, const BigInteger& right) {
	BigInteger temp;
	temp = left;
	temp -= right; // BigInteger& operator-= called
	return temp;
}

BigInteger &operator*=(BigInteger& left, const BigInteger& right) {
	if (Null(left) || Null(right)) {
		left = BigInteger();
		return left;
	}
	int n = left.m_value.size(), m = right.m_value.size();
	std::vector<int> v(n + m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i + j] += (left.m_value[i]) * (right.m_value[j]);
		}
	}
	n += m;
	left.m_value.resize(v.size());
	
	for (int s, i = 0, t = 0; i < n; i++) {
		s = t + v[i];
		v[i] = s % 10;
		t = s / 10;
		left.m_value[i] = v[i];
	}
	for (int i = n - 1; (i >= 1 && !v[i]); i--) {
		left.m_value.pop_back();
	}
	return left;
}


/*
	입출력 오버로딩
*/

std::istream &operator>>(std::istream& in, BigInteger& a) {
	std::string s;
	in >> s;
	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		if (!isdigit(s[i]))
			throw("INVALID NUMBER");
		a.m_value[n - i - 1] = s[i];
	}
	return in;
}

std::ostream &operator<<(std::ostream &out, const BigInteger &a) {
	for (int i = a.m_value.size() - 1; i >= 0; i--)
		std::cout << (short)a.m_value[i];
	return std::cout;
}
