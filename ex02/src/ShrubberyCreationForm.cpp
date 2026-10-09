#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): AForm("ShrubberyCreationForm",145,137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target){
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

void	ShrubberyCreationForm::executeAction() const{
	std::ofstream file ((_target + "_shrubbery").c_str());
	if (!file)
		throw AForm::FormNotExecuted("Creation of " + _target + "_shrubbery File failed.");
	file << "      ***    *       \n";
	file << "  *  *****  ***   *  \n";
	file << " ***  ***  ***** *** \n";
	file << "  |    |     |    |  \n";
}
