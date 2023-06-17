/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:25:41 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/12 02:08:45 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
public:
	// Constructors
	AForm();
	AForm(const AForm &copy);
	AForm(const std::string name, const std::string target, const size_t signGrade, const size_t execGrade);

	// Destructor
	virtual ~AForm();

	// Operators
	AForm &operator=(const AForm &assign);

	// Getters / Setters
	const std::string getName() const;
	const std::string getTarget() const;
	bool getSigned() const;
	const size_t &getSignGrade() const;
	const size_t &getExecGrade() const;

	// Other Member
	void beSigned(const Bureaucrat &bureaucrat);
	void execute(const Bureaucrat &executor) const;
	virtual void beExecuted(Bureaucrat const &bureaucrat) const = 0;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class NotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	const std::string _name;
	const std::string _target;
	bool _signed;
	const size_t _signGrade;
	const size_t _execGrade;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AForm &object);
