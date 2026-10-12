#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class AForm;
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &other);

		std::string	getName() const;
		int			getGrade() const;
		void		incGrade();
		void		decGrade();
		void		executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception 
		{
			private:
				std::string _msg;
			public:
				GradeTooHighException(const std::string &errTyp);
				~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception 
		{
			private:
				std::string _msg;
			public:
				GradeTooLowException(const std::string &errTyp);
				~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
