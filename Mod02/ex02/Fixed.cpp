/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:12:48 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/08 16:15:17 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed()
{
	// std::cout << "Default Constructor called of Fixed" << std::endl;
	_fixedNum = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy Constructor called of Fixed" << std::endl;
	_fixedNum = copy.getRawBits();
	// Fixed::operator=(copy);
}

Fixed::Fixed(const int val)
{
	// std::cout << "Int constructor called of Fixed" << std::endl;
	_fixedNum = val << _fixedFrac;
}

Fixed::Fixed(const float val)
{
	// std::cout << "Float constructor called of Fixed" << std::endl;
	_fixedNum = (int)roundf(val * (1 << _fixedFrac));
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called of Fixed" << std::endl;
}

// Operators
Fixed &Fixed::operator=(const Fixed &assign)
{
	// std::cout << "Copy assignment operator called of Fixed" << std::endl;
	_fixedNum = assign.getRawBits();
	return *this;
}

bool Fixed::operator==(const Fixed &equal)
{
	return _fixedNum == equal._fixedNum;
}

bool Fixed::operator!=(const Fixed &not_equal)
{
	return _fixedNum != not_equal._fixedNum;
}

bool Fixed::operator>(const Fixed &greater)
{
	return _fixedNum > greater._fixedNum;
}

bool Fixed::operator>=(const Fixed &greater_eq)
{
	return _fixedNum >= greater_eq._fixedNum;
}

bool Fixed::operator<(const Fixed &lesser)
{
	return _fixedNum < lesser._fixedNum;
}

bool Fixed::operator<=(const Fixed &lesser_eq)
{
	return _fixedNum <= lesser_eq._fixedNum;
}

Fixed Fixed::operator+(const Fixed &add)
{
	Fixed ret;

	ret.setRawBits(this->_fixedNum + add._fixedNum);
	return ret;
}

Fixed Fixed::operator-(const Fixed &sub)
{
	Fixed ret;

	ret.setRawBits(this->_fixedNum - sub._fixedNum);
	return ret;
}

Fixed Fixed::operator*(const Fixed &mul)
{
	Fixed ret;

	ret.setRawBits(this->_fixedNum * mul._fixedNum >> _fixedFrac);
	return ret;
}

Fixed Fixed::operator/(const Fixed &div)
{
	Fixed ret;

	ret.setRawBits(this->_fixedNum * (1 << _fixedFrac) / div._fixedNum);
	return ret;
}

Fixed &Fixed::operator++()
{
	this->_fixedNum++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->_fixedNum--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy = *this;
	++*this;
	return copy;
}

Fixed Fixed::operator--(int)
{
	Fixed copy = *this;
	--*this;
	return copy;
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return (first < second) ? first : second;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	return (first._fixedNum < second._fixedNum) ? first : second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return (first > second) ? first : second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	return (first._fixedNum > second._fixedNum) ? first : second;
}

// Getters / Setters
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called of Fixed" << std::endl;
	return _fixedNum;
}
void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called of Fixed" << std::endl;
	_fixedNum = raw;
	return;
}

// Converting Members
float Fixed::toFloat(void) const
{
	return (float)(_fixedNum) / (1 << _fixedFrac);
}

int Fixed::toInt(void) const
{
	return _fixedNum >> _fixedFrac;
}

// Operator overload
std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}
