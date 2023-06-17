/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:30:27 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/17 22:22:06 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        const std::string str(argv[1]);
        try
        {
            ScalarConverter S(str);
            S.convert(str);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cout << "./convert [char | int | float | double]" << std::endl;
    return 0;
}
