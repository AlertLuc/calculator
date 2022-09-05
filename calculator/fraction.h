#pragma once
#include <iostream>

class Fraction
{
public:
	Fraction(int numeratorand = 0, int denominator = 1) :
	m_numeratorand(numeratorand), m_denominator(denominator){}

	~Fraction() = default;
public:
	friend Fraction operator +(const Fraction&, const Fraction&);
	friend Fraction operator -(const Fraction&, const Fraction&);
	friend Fraction operator *(const Fraction&, const Fraction&);
	friend Fraction operator /(const Fraction&, const Fraction&);
    friend std::ostream& operator <<(std::ostream&, const Fraction&);
public:
    void reduction();
public:
	int m_numeratorand;
	int m_denominator;
};
