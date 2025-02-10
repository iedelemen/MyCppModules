#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
using std::cout;
using std::endl;
using std::string;

class Brain
{
	private:
		string _ideas[100];
	public:
		Brain();
		Brain(const Brain& obj);
		~Brain();
		Brain& operator=(const Brain& obj);

		void setIdea(string idea);
};

# endif
