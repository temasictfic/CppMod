/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:30:39 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/11 20:03:47 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // Bureaucrat nop("Nop", 0);
    // Bureaucrat bop("Bop", 151);
    Bureaucrat john("John", 1);
    Bureaucrat jim("Jim", 150);

    try
    {
        // john.incrGrade();
        // jim.decrGrade();
        john.decrGrade();
        jim.incrGrade();
        std::cout << john << std::endl;
        std::cout << jim << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
