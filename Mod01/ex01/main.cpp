/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:10:16 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/05 02:10:17 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	const int size = 20;

	Zombie *horde = zombieHorde(size, "BigBrainzz");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}