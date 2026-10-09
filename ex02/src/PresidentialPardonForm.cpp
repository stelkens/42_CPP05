#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const target): AForm("PresidentialPardonForm",25,5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target){
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

void	PresidentialPardonForm::executeAction() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}