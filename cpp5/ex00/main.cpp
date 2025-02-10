#include "Bureaucrat.hpp"

int main() {
	try {

		Bureaucrat john("John", 2);
		std::cout << john << std::endl;

		john.incrementGrade();
		std::cout << john << std::endl;

		// Error: too high grade
		john.incrementGrade();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		// Error: too low grade
		Bureaucrat invalidBureaucrat("Invalid", 200);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
