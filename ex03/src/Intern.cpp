#include "Intern.hpp"
#include "AForm.hpp"

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <iostream>

Intern::Intern(){
}

Intern::Intern(const Intern &other){
	*this = other;
}

Intern::~Intern(){
}

Intern::FormNotCreatedException::FormNotCreatedException(const std::string &errTyp): _msg("Error: Intern couldn't create form. " + errTyp){
}

Intern::FormNotCreatedException::~FormNotCreatedException() throw(){
}

Intern &Intern::operator=(const Intern &other){
	if (this != &other)
	{
	}
	return *this;
}

const std::string	Intern::_availForms[3] = {
	"shrubbery",
	"robotomy",
	"presidential"
};

AForm*	Intern::makeForm(std::string const &form, std::string const &target) const {
	int i;
	for(i = 0; i < 3; i++){
		if(_availForms[i] == form)
			break;
	}
	if (i < 3)
		std::cout << "Intern creates " << form << ".\n\n";
	switch (i)
	{
	case 0: {
		AForm *res = new ShrubberyCreationForm(target);
		return res;
	}
	case 1: {
		AForm *res = new RobotomyRequestForm(target);
		return res;
	}
	case 2: {
		AForm *res = new PresidentialPardonForm(target);
		return res;
	}
	default:{
		throw FormNotCreatedException("\"" + form + "\" doesn,t exist. Available forms are: \"shrubbery\" \"robotomy\" and \"presidential\".\n");
	}
	}
}

const char*	Intern::FormNotCreatedException::what() const throw (){
	return _msg.c_str();
}