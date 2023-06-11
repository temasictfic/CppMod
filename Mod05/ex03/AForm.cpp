/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:25:36 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/12 01:10:03 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm() : _name("DefaultForm"), _target("DefaultTarget"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Default Constructor called of Form" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _target(copy.getTarget()), _signed(copy.getSigned()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "Copy Constructor called of Form" << std::endl;
}

AForm::AForm(const std::string name, const std::string target, const size_t signGrade, const size_t execGrade) : _name(name), _target(target), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
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
AForm::~AForm()
{
	std::cout << "Destructor called of Form" << std::endl;
}

// Operators
AForm &AForm::operator=(const AForm &assign)
{
	//_signed = assign.getSigned();
	(void)assign;
	std::cout << "Assign operator called of Form" << std::endl;
	return *this;
}

// Getters / Setters
const std::string AForm::getName() const
{
	return _name;
}
const std::string AForm::getTarget() const
{
	return _target;
}
bool AForm::getSigned() const
{
	return _signed;
}
const size_t &AForm::getSignGrade() const
{
	return _signGrade;
}
const size_t &AForm::getExecGrade() const
{
	return _execGrade;
}

// Other Members
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getSigned() == false)
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
void AForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw(AForm::NotSignedException());
	else if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->beExecuted(executor);
	}
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
const char *AForm::NotSignedException::what() const throw()
{
	return "Form not signed!";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AForm &object)
{
	stream << "" << object.getName() << " for target " << object.getTarget() << ": signed=" << object.getSigned() << ", sign grade=" << object.getSignGrade() << ", exec grade=" << object.getExecGrade() << "" << std::endl;
	return stream;
}
