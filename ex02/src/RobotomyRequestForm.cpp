#include "RobotomyRequestForm.hpp"

#include "AForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const target): AForm("RobotomyRequestForm",72,45), _target("_" + target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target){
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

void	RobotomyRequestForm::executeAction() const{
	std::cout << "*DRRRRRRRR...DRRRRRRR...drilling noises...*\n";
	if (std::rand() % 2 == 0){
		std::cout << _target << " has been robotomized\n";
	}
	else
		std::cout << "Robotomy of " + _target + " faild.\n";
}