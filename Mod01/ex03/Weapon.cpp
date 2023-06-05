/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 03:49:55 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/05 03:49:56 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    this->_type = type;
}

Weapon::~Weapon()
{
}

std::string const& Weapon::getType() const{
    return this->_type;
}

void Weapon::setType(std::string newtype){
    this->_type = newtype;
}