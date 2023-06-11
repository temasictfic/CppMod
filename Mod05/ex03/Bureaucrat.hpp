/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:30:43 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/11 21:04:55 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class Bureaucrat
{
public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(const std::string name, size_t grade);

	// Destructor
	~Bureaucrat();

	// Operators
	Bureaucrat &operator=(const Bureaucrat &assign);

	// Getters / Setters
	const std::string getName() const;
	size_t getGrade() const;

	// Other Members
	void incrGrade();
	void decrGrade();
	void signForm(AForm &form);
	void executeForm(AForm const &form);

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
	size_t _grade;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Bureaucrat &object);

#endif
