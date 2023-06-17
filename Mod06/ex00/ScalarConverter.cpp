/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:29:50 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/17 23:47:31 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string literal)
{
    if (literal.empty())
        throw InvalidConversionInputException();
    if (literal.size() == 1 && !isdigit(literal[0]))
        _type = _charType;
    else if (literal != "nan" && literal.find('f') == std::string::npos && literal.find('.') == std::string::npos)
        _type = _intType;
    else
    {
        if (literal[literal.length() - 1] == 'f' && literal != "+inf" && literal != "-inf" && literal != "inf")
            _type = _floatType;
        else
            _type = _doubleType;
    }
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    _type = copy._type;
}
ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign)
{
    _type = assign._type;
    return *this;
}

const char *ScalarConverter::NonDisplayableCharException::what() const throw()
{
    return "Non displayable character";
}
const char *ScalarConverter::ImposibleConversionException::what() const throw()
{
    return "Imposible to convert";
}
const char *ScalarConverter::InvalidConversionInputException::what() const throw()
{
    return "Invalid conversion input";
}

char ScalarConverter::toChar(const std::string literal)
{
    std::string str(literal);
    if (str[0] == '+' || str[0] == '-')
        str.erase(0, 1);
    if (str[0] == '0')
        throw NonDisplayableCharException();
    long c = strtol(literal.c_str(), NULL, 10);
    if (c == 0L || c < CHAR_MIN || c > CHAR_MAX)
        throw ImposibleConversionException();
    else if (!isprint(c))
        throw NonDisplayableCharException();
    return static_cast<char>(c);
}

int ScalarConverter::toInt(const std::string literal)
{
    std::string str(literal);
    if (str[0] == '+' || str[0] == '-')
        str.erase(0, 1);
    if (str[0] == '0')
        return 0;
    long i = strtol(literal.c_str(), NULL, 10);
    if (i == 0L || i > INT_MAX || i < INT_MIN)
        throw ImposibleConversionException();
    return static_cast<int>(i);
}

double ScalarConverter::toDouble(const std::string literal)
{
    std::string str(literal);
    if (str[0] == '+' || str[0] == '-')
        str.erase(0, 1);
    if (str == "0.0f" || str == "0.0" || str == "0")
        return 0.0;
    double d = strtod(literal.c_str(), NULL);
    if (d == 0.0)
        throw ImposibleConversionException();
    return d;
}

void ScalarConverter::convert(const std::string literal)
{
    if (_type == _charType)
    {
        std::cout << "char  : " << literal << std::endl;
        std::cout << "int   : " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float : " << std::showpoint << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << std::showpoint << static_cast<double>(literal[0]) << std::endl;
    }
    else if (_type == _intType)
    {
        std::cout << "char  : ";
        try
        {
            std::cout << toChar(literal) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "int   : " << literal << std::endl;
        std::cout << "float : ";
        try
        {
            std::cout << std::showpoint << static_cast<float>(toDouble(literal)) << "f" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "double: ";
        try
        {
            std::cout << std::showpoint << toDouble(literal) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else if (_type == _floatType)
    {
        std::cout << "char  : ";
        try
        {
            std::cout << toChar(literal) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "int   : ";
        try
        {
            std::cout << toInt(literal) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "float : " << std::showpoint << static_cast<float>(toDouble(literal)) << "f" << std::endl;
        std::cout << "double: ";
        try
        {
            std::cout << std::showpoint << toDouble(literal) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else if (_type == _doubleType)
    {
        std::cout << "char  : ";
        try
        {
            std::cout << toChar(literal) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "int   : ";
        try
        {
            std::cout << toInt(literal) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "float : ";
        try
        {
            std::cout << std::showpoint << static_cast<float>(toDouble(literal)) << "f" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "double: " << std::showpoint << toDouble(literal) << std::endl;
    }
}
