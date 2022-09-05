#include "fraction.h"
#include <csignal>
fraction::fraction(int numeratorand, int denominator) :m_numeratorand(numeratorand), m_denominator(denominator)
{
	int m_numeratorand = 0;
	int m_denominator  = 1;
}

fraction::~fraction(){}

void fraction::reduction()
{
	int numeratorand, denominator, tmp, reduce;
	if (m_numeratorand != 0)
	{
		numeratorand = abs(m_numeratorand);
		denominator  = abs(m_denominator);
		tmp = denominator % numeratorand;
		while (tmp != 0)
		{
			denominator = numeratorand;
			numeratorand = tmp;
			tmp = denominator % numeratorand;
		}
		reduce = numeratorand;
		m_numeratorand = m_numeratorand / reduce;
		m_denominator = m_denominator / reduce;
		if (m_denominator < 0) {m_denominator = -m_denominator;m_numeratorand = -m_numeratorand;}
		if (m_denominator != 1) { std::cout << m_numeratorand << "/" << m_denominator << std::endl;}
	}
	else if(m_denominator == 1){std::cout << m_numeratorand << std::endl;}
	else{std::cout << "0" << std::endl;}
}

std::ostream& operator <<(std::ostream& stream, const fraction& num)
{
	stream << num.m_numeratorand << '/' << num.m_denominator;
	return stream;
}

fraction operator +(const fraction& firstnum, const fraction& secondnum)
{
	fraction results;
	results.m_numeratorand = firstnum.m_numeratorand * secondnum.m_denominator + secondnum.m_numeratorand * firstnum.m_denominator;
	results.m_denominator  = firstnum.m_denominator * secondnum.m_denominator ;
	results.reduction();
	return results;
}

fraction operator -(const fraction& firstnum, const fraction& secondnum)
{
	fraction results;
	results.m_numeratorand = firstnum.m_numeratorand * secondnum.m_denominator - secondnum.m_numeratorand * firstnum.m_denominator;
	results.m_denominator = firstnum.m_denominator * secondnum.m_denominator;
	results.reduction();
    return results;
}

fraction operator *(const fraction& firstnum, const fraction& secondnum)
{
	fraction results;
	results.m_numeratorand = firstnum.m_numeratorand * secondnum.m_numeratorand;
	results.m_denominator = firstnum.m_denominator * secondnum.m_denominator ;
	results.reduction();
	return results;
}

fraction operator /(const fraction& firstnum, const fraction& secondnum)
{
	fraction results;
	results.m_numeratorand = firstnum.m_numeratorand* secondnum.m_denominator;
	results.m_denominator  = firstnum.m_denominator * secondnum.m_numeratorand;
	results.reduction();
	return results;
}
