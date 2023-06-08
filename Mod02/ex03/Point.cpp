/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:38:36 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/08 16:19:35 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors
Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY())
{
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

// Destructor
Point::~Point()
{
}

// Operators
Point &Point::operator=(const Point &assign)
{
	(void)assign;
	// Can't assign to const x,y !
	return *this;
}

// Getters / Setters
Fixed const Point::getX() const
{
	return _x;
}
Fixed const Point::getY() const
{
	return _y;
}
