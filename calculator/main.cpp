#include <csignal>
#include <iostream>
#include"Fraction.h"
int main()
{
    char signal;
	int first_numeratorand, first_denominator;
	int second_numeratorand, second_denominator;

	std::cout << "firstfraction"<< std::endl;
	std::cin  >> first_numeratorand;
    std::cin.ignore(100, '/');
	std::cin  >> first_denominator;
	std::cout << "secondfraction" << std::endl;
	std::cin  >> second_numeratorand;
    std::cin.ignore(100, '/');
	std::cin  >> second_denominator;

	if (first_denominator == 0 || second_denominator == 0)
	{
		std::cout << "denominator != 0" << std::endl;
		return 0;
	}
    const Fraction firstnum(first_numeratorand, first_denominator), secondnum(second_numeratorand, second_denominator);
    
    std::cout << "select signal(+¡¢-¡¢*¡¢/)" << std::endl;
	std::cin  >> signal;
	switch (signal)
	{
	case '+':
	{
		std::cout << first_numeratorand << "/" << first_denominator << " + " <<
			second_numeratorand << "/" << second_denominator << " = " << firstnum + secondnum;
		break;
	}
	case '-':
	{
		std::cout << first_numeratorand << "/" << first_denominator << " - " <<
			second_numeratorand << "/" << second_denominator << " = " << firstnum - secondnum;
		break;
	}
	case '*':
	{
		std::cout << first_numeratorand << "/" << first_denominator << " * " <<
			second_numeratorand << "/" << second_denominator << " = " << firstnum * secondnum;
		break;
	}
	case '/':
	{
		std::cout << first_numeratorand << "/" << first_denominator << " / " <<
			second_numeratorand << "/" << second_denominator << " = " << firstnum / secondnum;
		break;
	}
	default: ;
	}
	std::cin.get();
	system("pause");
	return 0;
}


