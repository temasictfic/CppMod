/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:46:29 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/12 02:08:35 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
public:
	// Constructors
	Intern();
	Intern(const Intern &copy);

	// Destructor
	~Intern();

	// Other Members
	AForm *makeForm(const std::string name, const std::string target);

	// Operators
	Intern &operator=(const Intern &assign);

	// Exceptions
	class InvalidFormException : public std::exception
	{
	public:
		virtual char const *what(void) const throw();
	};

private:
};

#endif
