/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:24:15 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/07 20:34:19 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    // Constructors
    DiamondTrap();
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap(std::string name);

    // Destructor
    ~DiamondTrap();

    // Operators
    DiamondTrap &operator=(const DiamondTrap &assign);

    // Other Members
    void attack(std::string const &target);
    void whoAmI();

private:
    std::string _name;
};

#endif
