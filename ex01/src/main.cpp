	#include "Form.hpp"
	#include "Bureaucrat.hpp"
	#include <iostream>

	int main (){
		Form a ("a", 4, 5);
		std::cout << a;

		Bureaucrat Ela ("ela", 16);
		std::cout << Ela;

		try{
			Ela.signForm(a);
		}
		catch(const std::exception &e){
		std::cout << e.what() << std::endl;
		}

		std::cout << a;
	
		Bureaucrat Fabi ("fabi", 4);
		std::cout << Fabi;
		try{
			a.beSigned(Fabi);
		}
		catch(const std::exception &e){
		std::cout << e.what() << std::endl;
		}
		std::cout << a;

		try{
		Form tooHigh ("high", -1, 66);
		std::cout << tooHigh;
		}
		catch(const std::exception &e){
			std::cout << e.what() << std::endl;
		}

		try{
		Form High ("high_again", 44, 0);
		std::cout << High;
		}
		catch(const std::exception &e){
			std::cout << e.what() << std::endl;
		}

		try{
			Form tooLow ("low", 255, 15);
			std::cout << tooLow;
		}
		catch(const std::exception &e){
			std::cout << e.what() << std::endl;
		}


		try{
			Form Low ("low_again", 38, 154);
			std::cout << Low;
		}
		catch(const std::exception &e){
			std::cout << e.what() << std::endl;
		}

		Form b (a);
		std::cout << b;

		return 0;
	}