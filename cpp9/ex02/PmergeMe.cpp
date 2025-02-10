#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** arg){
	string val;
	cout << "\33c";
	cout << "Before: ";
	for (int i = 1; arg[i]; i++)
	{
		val = arg[i];
		if (val.empty())
			throw std::runtime_error("Empty expression");
		if (val.find_first_not_of("0123456789 ") != string::npos)
			throw std::runtime_error("Invalid expression");
		if (i < 11)
			cout << val << " ";
		else if (i == 11)
			cout << "[...]";
		check(val);
	}
	lets_sort();
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

void PmergeMe::check(string arg) {


	std::stringstream ss(arg);
	long value;
	ss >> value;
	if (ss.fail())
		throw std::runtime_error("\nFailed to convert token to int");
	if (value < 0 || value > 2147483647)
		throw std::runtime_error("\nInvalid number: " + arg);
	_vector.push_back(value);
	_deque.push_back(value);
}

void PmergeMe::lets_sort() {
	clock_t start_vector = clock();
	my_sort(_vector);
	clock_t end_vector = clock();

	clock_t start_deque = clock();
	my_sort(_deque);
	clock_t end_deque = clock();

	cout << "\nAfter: ";
	print(_vector);

	cout << "Time elapsed for vector: " << static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	cout << "Time elapsed for deque: " << static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	if (end_vector - start_vector < end_deque - start_deque)
		cout << "~vector~ is faster than deque by " << static_cast<double> (end_deque - start_deque) / (end_vector - start_vector) << " times" << endl;
	else
		cout << "~deque~ is faster than vector by " << static_cast<double> (end_vector - start_vector) / (end_deque - start_deque) << " times" << endl;

}


