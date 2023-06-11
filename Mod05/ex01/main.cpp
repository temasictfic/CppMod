/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:30:39 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/11 20:25:51 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat john("John", 5);

    std::cout << john << std::endl;

    try
    {
        john.incrGrade();
        john.incrGrade();
        std::cout << john << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form test("test", 151, 42);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Cannot initialize test because " << e.what() << std::endl;
    }

    Form b("b", 3, 3);
    Form c("c", 3, 20);
    std::cout << john << std::endl;
    std::cout << b << std::endl;
    john.signForm(b);
    john.signForm(b);

    try
    {
        john.decrGrade();
        std::cout << john << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    john.signForm(c);
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}
