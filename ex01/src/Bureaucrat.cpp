#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade){
	if (grade < 1 )
		throw Bureaucrat::GradeTooHighException("Construction of bureaucrat " + name + " failed.");
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Construction of bureaucrat " + name + " failed.");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name + "_copy"), _grade(other._grade){
	*this = other;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &errTyp): _msg("Error: Grade is too high. " + errTyp){
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &errTyp): _msg("Error: Grade is too low. " + errTyp){
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

std::string	Bureaucrat::getName() const{
	return _name;
}

int			Bureaucrat::getGrade() const{
	return _grade;
}

void		Bureaucrat::incGrade(){
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException("Incrementation of grade from " + _name + " failed.");
	--_grade;
}

void		Bureaucrat::decGrade(){
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException("Decrementation of grade from " + _name + " failed.");
	++_grade;
}

void		Bureaucrat::signForm(Form &form){
	try{
		form.beSigned(*this);
	}
	catch(const std::exception &e){
	std::cout << e.what() << std::endl;
	}
}

const char*		Bureaucrat::GradeTooHighException:: what() const throw(){
	return _msg.c_str();
}

const char*		Bureaucrat::GradeTooLowException::what() const throw(){
	return _msg.c_str();
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj){
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n";
	return out;
}