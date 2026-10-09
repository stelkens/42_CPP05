	#include "AForm.hpp"
	#include "Bureaucrat.hpp"
	#include "ShrubberyCreationForm.hpp"
	#include "RobotomyRequestForm.hpp"
	#include "PresidentialPardonForm.hpp"

	#include <iostream>

	int main (){
		
		ShrubberyCreationForm a("garden");
		std::cout << a;

		Bureaucrat Ela ("ela", 120);
		std::cout << Ela;

		try{
			a.beSigned(Ela);
			Ela.executeForm(a);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		
		RobotomyRequestForm b ("driving");
		std::cout << b;

		try{
			b.beSigned(Ela);
			Ela.executeForm(b);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}

		Bureaucrat Ale ("ale", 20);
		std::cout << Ale;

		try{
		b.beSigned(Ale);
		Ale.executeForm(b);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		
		PresidentialPardonForm c ("everything");
		std::cout << c;

		try{
			c.beSigned(Ale);
			Ale.executeForm(c);
			}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}

		Bureaucrat Beelbe ("Zaphod", 1);
		std::cout << Beelbe;

		try{
			c.beSigned(Ale);
			Beelbe.executeForm(c);
			}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}

		return 0;
	}