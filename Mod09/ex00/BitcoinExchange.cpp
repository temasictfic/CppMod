/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:35:15 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 20:40:44 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <cstdlib>

std::string dateCheck(std::string &timeStr);
float valueCheck(const std::string &valueStr);

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::BitcoinExchange(std::ifstream &db, std::ifstream &input)
{
    std::string dateDb, dateInput, rateDb, rateInput;
    float valueDb, valueInput;
    std::map<std::string, float> dbMap;

    std::getline(db, dateDb, ',');
    std::getline(db, rateDb);
    while (!db.eof())
    {
        std::getline(db, dateDb, ',');
        std::getline(db, rateDb);
        valueDb = strtof(rateDb.c_str(), NULL);
        dbMap.insert(std::pair<std::string, float>(dateDb, valueDb));
    }
    std::getline(input, dateInput);
    while (!input.eof())
    {
        std::getline(input, dateInput);
        size_t idx = dateInput.find('|');
        if (idx != std::string::npos && dateInput.length() - idx >= 2)
        {
            rateInput = dateInput.substr(idx + 2, dateInput.length() - idx - 2);
            valueInput = valueCheck(rateInput);
            dateInput = dateInput.substr(0, idx);
            dateInput = dateCheck(dateInput);
        }
        else
        {
            dateInput.resize(10);
            dateInput = "Error: bad input => " + dateInput;
            valueInput = -3;
        }
        if (dateInput[0] == 'E')
            std::cout << dateInput << std::endl;
        else if (valueInput <= 0)
        {
            if (valueInput == 0)
                std::cout << "Error: not a number." << std::endl;
            else if (valueInput == -1)
                std::cout << "Error: too large number." << std::endl;
            else if (valueInput == -2)
                std::cout << "Error: not a positive number." << std::endl;
        }
        else
        {
            std::map<std::string, float>::iterator dit;

            dit = dbMap.find(dateInput);
            if (dit != dbMap.end())
                std::cout << dateInput << " => " << std::showpoint << valueInput << " = " << valueInput * dit->second << std::endl;
            else
                std::cout << "Error: date not found in database." << std::endl;
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    (void)copy;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
    (void)assign;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}
