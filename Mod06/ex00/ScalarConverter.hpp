/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:29:40 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/17 23:47:27 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
private:
    enum type
    {
        _charType,
        _intType,
        _floatType,
        _doubleType
    } _type;

public:
    ScalarConverter(const std::string literal);
    ScalarConverter(const ScalarConverter &copy);
    ~ScalarConverter();

    ScalarConverter &operator=(const ScalarConverter &assign);

    char toChar(const std::string literal);
    int toInt(const std::string literal);
    double toDouble(const std::string literal);
    void convert(const std::string literal);

    class NonDisplayableCharException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class ImposibleConversionException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class InvalidConversionInputException : public std::exception
    {
        virtual const char *what() const throw();
    };
};
