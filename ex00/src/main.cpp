#include "Bureaucrat.hpp"
#include <iostream>

int main (){

	Bureaucrat Bob ("bob", 150);
	std::cout << Bob;
	try{
		Bob.decGrade();
		std::cout << Bob;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	try{
		Bob.incGrade();
		std::cout << Bob;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	Bureaucrat Bobby ("bobby", 1);
	std::cout << Bobby;

	Bobby = Bob;
	std::cout << Bobby;

	Bureaucrat Titi ("titi", 5);
	std::cout << Titi;

	try{
		for(int i = 0; i < 5; i ++){
			Titi.incGrade();
			std::cout << Titi;
		}
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat tooHigh ("high", -1);
		std::cout << tooHigh;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat tooLow ("low", 255);
		std::cout << tooLow;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}	

	Bob.decGrade();
	Bureaucrat Bobobo (Bob);
	std::cout << Bobobo;

	return 0;
}