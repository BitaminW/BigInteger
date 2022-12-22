#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>




#define ull unsigned long long





class BigInteger{
private:
	std::string m_value;

public:
	// Constructor :  
	BigInteger();
	BigInteger(ull n = 0);
	BigInteger(std::string &);
	BigInteger(const char *);
	BigInteger(BigInteger &);


	~BigInteger();

	// Helper Functions..
	friend void divide_by_2(BigInteger& a);
	friend void Null(const BigInteger&);
	friend int	Length(const BigInteger&);
	int operator[](const int)const;
	
	

	//	  ..Operator Overloading..  	//
	

	//	Direct assignment
	BigInteger& operator=(const BigInteger&);


	//	Incrementation
	BigInteger& operator++();
	BigInteger& operator++(int temp);
	BigInteger& operator--();
	BigInteger& operator--(int temp);


	//	(Addition , Subtraction)
	friend BigInteger& operator+=(BigInteger&, const BigInteger&);
	friend BigInteger& operator-=(BigInteger&, const BigInteger&);
	friend BigInteger operator+(const BigInteger&, const BigInteger&);
	friend BigInteger operator-(const BigInteger&, const BigInteger&);


	// Comparison operators



public:


};
