/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:12:57 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/06 16:49:07 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <iostream>

class Fixed
{
public:
	// Constructors
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int);
	Fixed(const float);

	// Destructor
	~Fixed();

	// Operators
	Fixed &operator=(const Fixed &assign);

	// Getters / Setters
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Members
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixedNum;
	static const int _fixedFrac = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif