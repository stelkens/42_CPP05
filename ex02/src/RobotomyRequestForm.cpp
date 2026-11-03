#include "RobotomyRequestForm.hpp"

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const target): AForm("RobotomyRequestForm",72,45), _target(target){
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
	std::cout << "***DRRRRRRRR...DRRRRRRR...drilling noises...***\n";
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0){
		std::cout << _target << " has been robotomized\n";
	}
	else
		std::cout << "X robotomy of " + _target + " faild. X\n";
}