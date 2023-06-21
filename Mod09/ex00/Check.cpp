/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:34:58 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 20:34:59 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>

// https://cboard.cprogramming.com/c-programming/169114-how-convert-string-time_t.html
std::string dateCheck(std::string &dateStr)
{
    int year = 0, month = 0, day = 0;
    if (sscanf(dateStr.c_str(), "%4d-%2d-%2d", &year, &month, &day) == 3)
    {
        if (!(year > 1900 && (month > 0 && month < 13) && (month > 0 && month < 32)))
            return "Error: bad input => " + dateStr;
        dateStr.resize(10);
        return dateStr;
    }
    else
        return "Error: bad input => " + dateStr;
}

float valueCheck(const std::string &valueStr)
{
    float value = strtof(valueStr.c_str(), NULL);
    if (valueStr != " 0" && value == 0)
        return 0; //"Error: Not a number => " + valueStr;
    else if (value > 1000)
        return -1; //"Error: Too Large number => " + valueStr;
    else if (!(value > 0))
        return -2; //"Error: Not a positive number => " + valueStr;
    else
        return value;
}
