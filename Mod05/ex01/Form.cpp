/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:25:36 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/11 20:25:40 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form() : _name("DefaultForm"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Default Constructor called of Form" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.getSigned()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "Copy Constructor called of Form" << std::endl;
}

Form::Form(const std::string name, const size_t signGrade, const size_t execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150)
		throw GradeTooLowException();
	if (this->_execGrade < 1)
		throw GradeTooHighException();
	else if (this->_execGrade > 150)
		throw GradeTooLowException();

	std::cout << "Fields Constructor called of Form" << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << "Destructor called of Form" << std::endl;
}

// Operators
Form &Form::operator=(const Form &assign)
{
	//_signed = assign.getSigned();
	(void)assign;
	std::cout << "Assign operator called of Form" << std::endl;
	return *this;
}

// Getters / Setters
const std::string Form::getName() const
{
	return _name;
}
bool Form::getSigned() const
{
	return _signed;
}
const size_t &Form::getSignGrade() const
{
	return _signGrade;
}
const size_t &Form::getExecGrade() const
{
	return _execGrade;
}

// Other Members
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed == false)
	{
		if (bureaucrat.getGrade() <= this->getSignGrade())
		{
			_signed = true;
			std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		std::cout << _name << " already signed!" << std::endl;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Form &object)
{
	stream << "" << object.getName() << ": signed=" << object.getSigned() << ", sign grade=" << object.getSignGrade() << ", exec grade=" << object.getExecGrade() << "" << std::endl;
	return stream;
}
