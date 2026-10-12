#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;
class Intern
{
	private:
		static const std::string _availForms[3];

	public:
		Intern();
		Intern(const Intern &other);
		~Intern();

		Intern &operator=(const Intern &other);

		AForm*	makeForm(std::string const &form, std::string const &target) const;

		class		FormNotCreatedException : public std::exception
		{
			private:
				std::string _msg;
			public:
				FormNotCreatedException(const std::string &errTyp);
				~FormNotCreatedException() throw();
				virtual const char* what() const throw();
		};
};

#endif
