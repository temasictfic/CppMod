/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:30:51 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/11 22:47:06 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("Anonymous"), _grade(1)
{
	std::cout << "Default Constructor called of Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Copy Constructor called of Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, size_t grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
	std::cout << "Fields Constructor called of Bureaucrat" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called of Bureaucrat" << std::endl;
}

// Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	_grade = assign.getGrade();
	std::cout << "Assign operator called of Bureaucrat" << std::endl;
	return *this;
}

// Getters / Setters
const std::string Bureaucrat::getName() const
{
	return _name;
}
size_t Bureaucrat::getGrade() const
{
	return _grade;
}

// Other Members
void Bureaucrat::incrGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}
void Bureaucrat::decrGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}
void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade can be 1 atmost";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade can be 150 minimum";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << "" << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << std::endl;
	return stream;
}
