/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:24:15 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/07 20:34:19 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    // Constructors
    FragTrap();
    FragTrap(const FragTrap &copy);
    FragTrap(std::string name);

    // Destructor
    ~FragTrap();

    // Operators
    FragTrap &operator=(const FragTrap &assign);

    // Other Members
    void attack(std::string const &target);
    void highFivesGuys(void);

private:
};

#endif