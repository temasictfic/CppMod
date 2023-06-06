/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:12:48 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/06 15:12:49 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called of Fixed" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called of Fixed" << std::endl;
	_fixedNum = assign.getRawBits();
	return *this;
}


// Getters / Setters
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called of Fixed" << std::endl;
	return _fixedNum;
}
void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called of Fixed" << std::endl;
	_fixedNum = raw;  
	return;
}
