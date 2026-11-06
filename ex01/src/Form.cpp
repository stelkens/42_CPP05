#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

Form::Form(std::string formName, int const gradeToSign, int const gradeToExecute):
_formName(formName),  _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException("Highest grade in Form is 1.");
	else if(gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException("Lowest grade in Form is 150.");
}

Form::Form(const Form &other): _formName(other._formName + "_copy"), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
	this->_signed = other._signed;
}

Form::~Form(){
}

Form::GradeTooHighException::~GradeTooHighException() throw(){
}

Form::GradeTooLowException::~GradeTooLowException() throw(){
}

Form::GradeTooHighException::GradeTooHighException(const std::string &errTyp): _msg("Grade is too high. " + errTyp){
}

Form::GradeTooLowException::GradeTooLowException(const std::string &errTyp): _msg("Grade is too low. " + errTyp){
}


Form &Form::operator=(const Form &other){
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}


std::string	Form::getName() const{
	return _formName;
}

bool		Form::getSignedStatus() const{
	return _signed;
}

int			Form::getGradeToSign() const{
	return _gradeToSign;
}

int			Form::getGradeToExecute() const{
	return _gradeToExecute;
}

void		Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() <= getGradeToSign()){
		_signed = true;
		std::cout << bureaucrat.getName() << " signed " << _formName << ".\n";
	}
	else
		throw Form::GradeTooLowException("Bureaucrat " + bureaucrat.getName() + " needs higher grade to sign " + _formName);
}

const char*		Form::GradeTooHighException:: what() const throw(){
	return _msg.c_str();
}

const char*		Form::GradeTooLowException:: what() const throw(){
	return _msg.c_str();
}

std::ostream	&operator<<(std::ostream &out, const Form &obj){
	out << obj.getName() << ":\t\tsigned\t\t\t\t" << std::boolalpha << obj.getSignedStatus() << "\n\t\trequired grade to sign\t\t" << obj.getGradeToSign() 
		<< "\n\t\trequired grade to execute\t" << obj.getGradeToExecute() << std::endl;
	return out;
}