#pragma once
#include <iostream>
#include <cmath>
class fraction
{
public:
	fraction(int numeratorand, int denominator);
	fraction() {};
	~fraction();
public:
	friend fraction operator +(const fraction&, const fraction&);
	friend fraction operator -(const fraction&, const fraction&);
	friend fraction operator *(const fraction&, const fraction&);
	friend fraction operator /(const fraction&, const fraction&);
    friend std::ostream& operator <<(std::ostream&, const fraction&);
public:
    void reduction();
public:
	int m_numeratorand;
	int m_denominator;
};
