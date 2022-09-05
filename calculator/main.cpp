#include <csignal>
#include <iostream>
#include"fraction.h"
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
	if (first_denominator == 0 || second_denominator == 0){std::cout << "denominator != 0" << std::endl;exit(0);}
    fraction results;
	fraction firstnum(first_numeratorand, first_denominator), secondnum(second_numeratorand, second_denominator);
    
    std::cout << "select signal(+¡¢-¡¢*¡¢/£©" << std::endl;
	std::cin  >> signal;
	switch (signal)
	{
	case '+':
        
		std::cout << first_numeratorand << "/" << first_denominator << " + " << second_numeratorand << "/" << second_denominator << " = ";
		results = firstnum + secondnum;
		break;
	case '-':
		std::cout << first_numeratorand << "/" << first_denominator << " - " << second_numeratorand << "/" << second_denominator << " = ";
		results = firstnum - secondnum;
		break;
	case '*':
		std::cout << first_numeratorand << "/" << first_denominator << " * " << second_numeratorand << "/" << second_denominator << " = ";
		results = firstnum * secondnum;
		break;
	case '/':
		std::cout << first_numeratorand << "/" << first_denominator << " / " << second_numeratorand << "/" << second_denominator << " = ";
		results = firstnum / secondnum;
		break;
	}
	std::cin.get();
	system("pause");
	return 0;
}


