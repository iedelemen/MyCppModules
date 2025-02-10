#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0){}

Fixed::Fixed(const int intValue)
{
	_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	_value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed(){}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		_value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}


bool Fixed::operator>(const Fixed& other) const
{
	return _value > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
	return _value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
	return _value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
	return _value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
	return _value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
	return _value != other.getRawBits();
}


Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(toFloat() / other.toFloat());
}


Fixed& Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}
