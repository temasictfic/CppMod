/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:15:46 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/07 22:20:45 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	// Constructors
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap(std::string name);

	// Destructor
	~ScavTrap();

	// Operators
	ScavTrap &operator=(const ScavTrap &assign);

	// Other Members
	void attack(std::string const &target);
	void guardGate();

private:
};

#endif