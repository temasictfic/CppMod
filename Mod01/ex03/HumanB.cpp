/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 03:50:08 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/05 17:42:16 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &wp)
{
    this->_wpB = &wp;
}
void HumanB::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_wpB->getType() << std::endl;
}
