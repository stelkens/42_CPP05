#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

AForm::AForm(std::string formName, int const gradeToSign, int const gradeToExecute):
_formName(formName),  _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException("Highest grade in AForm is 1.");
	else if(gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException("Lowest grade in AForm is 150.");
}

AForm::AForm(const AForm &other): _formName(other._formName + "_copy"), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
	this->_signed = other._signed;
}

AForm::~AForm(){
}

AForm::GradeTooHighException::~GradeTooHighException() throw(){
}

AForm::GradeTooLowException::~GradeTooLowException() throw(){
}

AForm::FormNotExecuted::~FormNotExecuted() throw(){
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &errTyp): _msg("Error: Grade is too high. " + errTyp){
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &errTyp): _msg("Error: Grade is too low. " + errTyp){
}

AForm::FormNotExecuted::FormNotExecuted(const std::string &errTyp): _msg("Error: Form couldn't be executet. " + errTyp){
}

AForm &AForm::operator=(const AForm &other){
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}


std::string	AForm::getName() const{
	return _formName;
}

bool		AForm::getSignedStatus() const{
	return _signed;
}

int			AForm::getGradeToSign() const{
	return _gradeToSign;
}

int			AForm::getGradeToExecute() const{
	return _gradeToExecute;
}

void		AForm::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > getGradeToSign())
		throw AForm::GradeTooLowException("Bureaucrat " + bureaucrat.getName() + " needs higher grade to sign " + _formName);
	_signed = true;
	std::cout << bureaucrat.getName() << " signed " << _formName << ".\n";
}

void		AForm::execute(Bureaucrat const &executor) const{
	if (!_signed)
		throw AForm::FormNotExecuted("Form " + _formName + " isn't signed.");
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::FormNotExecuted("Bureaucrat " + executor.getName() + " needs higher grade to execute " + _formName);
	try{
		executeAction();
		std::cout << executor.getName() << " executed " << _formName << "\n";
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
}

const char*		AForm::GradeTooHighException:: what() const throw(){
	return _msg.c_str();
}

const char*		AForm::GradeTooLowException:: what() const throw(){
	return _msg.c_str();
}

const char*		AForm::FormNotExecuted:: what() const throw (){
	return _msg.c_str();
}

std::ostream	&operator<<(std::ostream &out, const AForm &obj){
	out << obj.getName() << ":\n\t\tsigned\t\t\t\t" << std::boolalpha << obj.getSignedStatus() << "\n\t\trequired grade to sign\t\t" << obj.getGradeToSign() 
		<< "\n\t\trequired grade to execute\t" << obj.getGradeToExecute() << std::endl;
	return out;
}