/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:02:40 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/08 14:19:42 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
    std::cout << this->_name << ": "
              << "Destroyed!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": "
              << "BraiiiiiiinnnzzzZ..." << std::endl;
}
