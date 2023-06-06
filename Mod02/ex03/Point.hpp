/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:38:27 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/06 21:43:45 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	// Constructors
	Point();
	Point(const Point &copy);
	Point(const float x, const float y);

	// Destructor
	~Point();

	// Operators
	Point &operator=(const Point &assign);

	// Getters / Setters
	Fixed const getX() const;
	Fixed const getY() const;

private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif