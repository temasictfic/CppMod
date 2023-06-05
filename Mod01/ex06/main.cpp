/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:13:22 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/05 22:26:08 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        Harl harl;
        std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        size_t l = 5;

        for (size_t i = 0; i < 4; i++)
            if (levels[i] == argv[1])
                l = i;
        if (l == 5)
        {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            return (0);
        }
        for (size_t i = 0; i <= l; i++)
        {
            std::cout << "[" << levels[i] << "]" << std::endl;
            harl.complain(levels[i]);
            std::cout << std::endl;
        }
    }
    else
        std::cout << "Usage: ./harlfilter [\"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\"]" << std::endl;
    return (0);
}

/*      [-Werror=implicit-fallthrough=]
**
**         switch (i)
**         {
**         case 0:
**             std::cout << "[" << levels[0] << "]" << std::endl;
**             harl.complain(levels[0]);
**             std::cout << std::endl;
**         case 1:
**             std::cout << "[" << levels[1] << "]" << std::endl;
**             harl.complain(levels[1]);
**             std::cout << std::endl;
**         case 2:
**             std::cout << "[" << levels[2] << "]" << std::endl;
**             harl.complain(levels[2]);
**             std::cout << std::endl;
**         case 3:
**             std::cout << "[" << levels[3] << "]" << std::endl;
**             harl.complain(levels[3]);
**             std::cout << std::endl;
**             break;
**         default:
**             break;
**         }
*/