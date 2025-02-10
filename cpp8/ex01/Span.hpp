#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span(unsigned int n);
		Span(const Span &span);
		~Span();
		Span &operator=(const Span &span);

		void addNumber(int n);
		void improveAddNumber(int n, int m);
		int shortestSpan();
		int longestSpan();
};

#endif


