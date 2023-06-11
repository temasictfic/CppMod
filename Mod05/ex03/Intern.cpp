/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:46:25 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/12 01:43:31 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "Default Constructor called of Intern" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of Intern" << std::endl;
}

// Destructor
Intern::~Intern()
{
	std::cout << "Destructor called of Intern" << std::endl;
}

// Operators
Intern &Intern::operator=(const Intern &assign)
{
	(void)assign;
	std::cout << "Assign operator called of Intern" << std::endl;
	return *this;
}

// Other Members
AForm *Intern::makeForm(const std::string name, const std::string target)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = 0;
	AForm *form = NULL;
	while (i < 3 && forms[i] != name)
		i++;
	switch (i)
	{
	case 0:
		form = new PresidentialPardonForm(target);
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		break;
	case 2:
		form = new ShrubberyCreationForm(target);
		break;
	default:
		throw InvalidFormException();
	}
	std::cout << "Intern creates " << name << std::endl;
	return form;
}

// Exceptions
char const *Intern::InvalidFormException::what(void) const throw()
{
	return ("Invalid Form Request");
}
