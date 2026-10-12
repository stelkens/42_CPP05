#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;
class AForm
{
	private:
		std::string const	_formName;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		AForm(std::string formName, int const gradeToSign, int const gradeToExecute);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &other);

		std::string		getName() const;
		bool			getSignedStatus() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		void			beSigned(const Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual	void	executeAction() const = 0;

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
				GradeTooLowException(const std::string &errTyp);
				~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};

		class		FormNotExecutedException : public std::exception
		{
			private:
				std::string _msg;
			public:
				FormNotExecutedException(const std::string &errTyp);
				~FormNotExecutedException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif
