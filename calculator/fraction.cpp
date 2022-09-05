#include "Fraction.h"
#include <csignal>

void Fraction::reduction()
{
	if (m_numeratorand != 0)
	{
		// 
		int numeratorand = abs(m_numeratorand);
		int denominator = abs(m_denominator);
		int tmp = denominator % numeratorand;

		// 
		while (tmp != 0)
		{
			denominator = numeratorand;
			numeratorand = tmp;
			tmp = denominator % numeratorand;
		}

		const int reduce = numeratorand;
		m_numeratorand = m_numeratorand / reduce;
		m_denominator = m_denominator / reduce;


		if (m_denominator < 0)
		{
			m_denominator = -m_denominator;m_numeratorand = -m_numeratorand;
		}
		if (m_denominator != 1)
		{
			std::cout << m_numeratorand << "/" << m_denominator << std::endl;
		}
        if(abs(m_numeratorand) == abs(m_denominator))
        {
	        std::cout <<"1"<< std::endl;
        }
	}
	else if(m_denominator == 1)
	{
		std::cout << m_numeratorand << std::endl;
	}
	else
	{
		std::cout << "0" << std::endl;
	}
}

std::ostream& operator <<(std::ostream& stream, const Fraction& num)
{
	stream << num.m_numeratorand << '/' << num.m_denominator;
	return stream;
}

Fraction operator +(const Fraction& firstnum, const Fraction& secondnum)
{
	Fraction results;
	results.m_numeratorand = firstnum.m_numeratorand * secondnum.m_denominator + secondnum.m_numeratorand * firstnum.m_denominator;
	results.m_denominator  = firstnum.m_denominator * secondnum.m_denominator ;
	results.reduction();
	return results;
}

Fraction operator -(const Fraction& firstnum, const Fraction& secondnum)
{
	Fraction results;
	results.m_numeratorand = firstnum.m_numeratorand * secondnum.m_denominator - secondnum.m_numeratorand * firstnum.m_denominator;
	results.m_denominator = firstnum.m_denominator * secondnum.m_denominator;
	results.reduction();
    return results;
}

Fraction operator *(const Fraction& firstnum, const Fraction& secondnum)
{
	Fraction results;
	results.m_numeratorand = firstnum.m_numeratorand * secondnum.m_numeratorand;
	results.m_denominator = firstnum.m_denominator * secondnum.m_denominator ;
	results.reduction();
	return results;
}

Fraction operator /(const Fraction& firstnum, const Fraction& secondnum)
{
	Fraction results;
	results.m_numeratorand = firstnum.m_numeratorand* secondnum.m_denominator;
	results.m_denominator  = firstnum.m_denominator * secondnum.m_numeratorand;
	results.reduction();
	return results;
}
