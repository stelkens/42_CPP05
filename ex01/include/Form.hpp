#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;
class Form
{
	private:
		std::string const	_formName;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		Form(std::string formName, int const gradeToSign, int const gradeToExecute);
		Form(const Form &other);
		~Form();

		Form &operator=(const Form &other);

		std::string	getName() const;
		bool		getSignedStatus() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat &bureaucrat);

		class		GradeTooHighException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooHighException(const std::string& errTyp);
				~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};
		class		GradeTooLowException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooLowException(const std::string& errTyp);
				~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &obj);

#endif
