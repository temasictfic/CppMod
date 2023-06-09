/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:11:28 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/09 19:14:53 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	_type = "Cat";
	_catBrain = new Brain();
	std::cout << "Default Constructor called of " << _type << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	_type = copy.getType();
	_catBrain = new Brain(copy.getBrain());
	std::cout << "Copy Constructor called of " << _type << std::endl;
}

Cat::Cat(std::string type)
{
	_type = type;
	_catBrain = new Brain();
	std::cout << "Fields Constructor called of " << _type << std::endl;
}

// Destructor
Cat::~Cat()
{
	delete _catBrain;
	std::cout << "Destructor called of " << _type << std::endl;
}

// Operators
Cat &Cat::operator=(const Cat &assign)
{
	_type = assign.getType();
	_catBrain = new Brain(assign.getBrain());
	std::cout << "Assign Operator called of " << _type << std::endl;
	return *this;
}

void Cat::makeSound() const
{

	std::cout << "Meow" << std::endl;
}

const Brain &Cat::getBrain() const
{
	return *_catBrain;
}
