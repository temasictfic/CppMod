/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:12:57 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/06 21:44:53 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

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
	bool operator==(const Fixed &equal);
	bool operator!=(const Fixed &not_equal);
	bool operator>(const Fixed &greater);
	bool operator>=(const Fixed &greater);
	bool operator<(const Fixed &lesser_eq);
	bool operator<=(const Fixed &greater_eq);
	Fixed operator+(const Fixed &add);
	Fixed operator-(const Fixed &sub);
	Fixed operator*(const Fixed &mul);
	Fixed operator/(const Fixed &div);
	Fixed &operator++();
	Fixed operator++(int); // post_incr
	Fixed &operator--();
	Fixed operator--(int); // post_decr

	// Getters / Setters
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Other Members
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(const Fixed &first, const Fixed &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(const Fixed &first, const Fixed &second);

private:
	int _fixedNum;
	static const int _fixedFrac = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif