/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:12:48 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/06 16:52:59 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed()
{
	std::cout << "Default Constructor called of Fixed" << std::endl;
	_fixedNum = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called of Fixed" << std::endl;
	_fixedNum = copy.getRawBits();
	// Fixed::operator=(copy);
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called of Fixed" << std::endl;
	_fixedNum = val << _fixedFrac;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called of Fixed" << std::endl;
	_fixedNum = (int)roundf(val * (1 << _fixedFrac));
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called of Fixed" << std::endl;
}

// Operators
Fixed &Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called of Fixed" << std::endl;
	_fixedNum = assign.getRawBits();
	return *this;
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