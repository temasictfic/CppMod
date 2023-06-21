/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:34:46 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 20:34:51 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <cstring>

int main(int argc, char const *argv[])
{
    (void)argc;
    /*
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        std::cout << "Usage: ./btc [Input File]" << std::endl;
    }*/
    std::ifstream db("data.csv");
    std::ifstream input(argv[1]);
    if (input.good() && db.good())
        BitcoinExchange(db, input);
    else
        std::cerr << strerror(errno) << std::endl;
    return 0;
}
