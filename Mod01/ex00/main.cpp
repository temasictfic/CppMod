/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:07:39 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/04 22:07:40 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie ZombieInst;
    std::string name = "sansar";
    ZombieInst.newZombie(name);
    ZombieInst.randomChump(name);
    ZombieInst.announce();
    return 0;
}
