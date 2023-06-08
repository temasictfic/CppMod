/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 03:50:15 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/08 14:24:36 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &wp) : _name(name), _wpA(wp)
{
}

HumanA::~HumanA()
{
}

void HumanA::setWeapon(Weapon &wp)
{
    this->_wpA = wp;
}

void HumanA::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_wpA.getType() << std::endl;
}
