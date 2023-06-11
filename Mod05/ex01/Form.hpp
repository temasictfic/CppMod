/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:25:41 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/11 20:25:45 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
public:
	// Constructors
	Form();
	Form(const Form &copy);
	Form(const std::string name, const size_t signGrade, const size_t execGrade);

	// Destructor
	~Form();

	// Operators
	Form &operator=(const Form &assign);

	// Getters / Setters
	const std::string getName() const;
	bool getSigned() const;
	const size_t &getSignGrade() const;
	const size_t &getExecGrade() const;

	// Other Member
	void beSigned(const Bureaucrat &bureaucrat);

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	const std::string _name;
	bool _signed;
	const size_t _signGrade;
	const size_t _execGrade;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Form &object);

#endif
