	#include "AForm.hpp"
	#include "Bureaucrat.hpp"
	#include "ShrubberyCreationForm.hpp"
	#include "RobotomyRequestForm.hpp"
	#include "PresidentialPardonForm.hpp"
	#include "Intern.hpp"

	#include <iostream>

	int main (){
		
		Intern a;
		AForm* sf;

		 Bureaucrat Ela ("ela", 120);

		try{
			sf = a.makeForm("shrubbery", "house");
			std::cout << *sf;
			sf->beSigned(Ela);
			Ela.executeForm(*sf);
		}
		catch (std::exception &e){
		std::cout << e.what() << std::endl;
		}
		delete sf;
		sf = NULL;

		AForm* rrf;
		Bureaucrat Ale ("ale", 5);

		try{
			rrf = a.makeForm("robotomy", "car");
			std::cout << *rrf;
			rrf->beSigned(Ale);
			Ale.executeForm(*rrf);
		}
		catch (std::exception &e){
		std::cout << e.what() << std::endl;
		}
		delete rrf;
		rrf = NULL;

		try{
			rrf = a.makeForm("presidential", "car");
			std::cout << *rrf;
			rrf->beSigned(Ale);
			Ale.executeForm(*rrf);
		}
		catch (std::exception &e){
		std::cout << e.what() << std::endl;
		}
		delete rrf;
		rrf = NULL;

		return 0;
	}