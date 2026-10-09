	#include "AForm.hpp"
	#include "Bureaucrat.hpp"
	#include "ShrubberyCreationForm.hpp"
	#include "RobotomyRequestForm.hpp"
	#include <iostream>

	int main (){
		
		ShrubberyCreationForm a("garden");
		std::cout << a;

		Bureaucrat Ela ("ela", 16);
		std::cout << Ela;

		a.beSigned(Ela);
		Ela.executeForm(a);

		RobotomyRequestForm b ("driving");
		std::cout << b;

		b.beSigned(Ela);
		Ela.executeForm(b);


		return 0;
	}