/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:56:08 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/08 16:51:34 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap rucio;
    ClapTrap don("Don Quijote");
    ClapTrap zancaz("Zancaz");

    don.attack("windmill");
    zancaz.attack("windmill");
    rucio.attack("windmill");
    don.takeDamage(5);
    zancaz.takeDamage(9);
    rucio.takeDamage(10);
    don.beRepaired(10);
    zancaz.beRepaired(10);
    rucio.beRepaired(10);
    rucio.attack("windmill");
}
