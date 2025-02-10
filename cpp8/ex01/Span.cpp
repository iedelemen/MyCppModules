#include "Span.hpp"
#include <iostream>
#include <unistd.h>
Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &span)
{
	*this = span;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &span)
{
	_n = span._n;
	_v = span._v;
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() == _n)
		throw std::exception();
	_v.push_back(n);
}
void Span::improveAddNumber(int n, int m)
{
	srand(time(NULL));
	for (; n <= m; n++)
		addNumber(rand() % m);
}


int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (unsigned int i = 2; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}


