#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 40);
		Form taxForm("Tax Form", 30, 10);

		std::cout << taxForm << std::endl;

		// Error: cannot sign grade is too low
		alice.signForm(taxForm);

		std::cout << taxForm << std::endl;

		Bureaucrat boss("Boss", 20);
		boss.signForm(taxForm);

		std::cout << taxForm << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
