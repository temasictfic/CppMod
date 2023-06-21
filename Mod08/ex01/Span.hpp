/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:59:48 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 02:59:49 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <vector>
#include "iostream"

class Span
{
private:
    Span(void);
    std::vector<int> _vec;
    unsigned int _size;

public:
    Span(const unsigned int &N);
    Span(const Span &copy);
    ~Span();
    Span &operator=(const Span &assign);

    void addNumber(int n);
    void addNumber(const std::vector<int>::iterator &begin,
                   const std::vector<int>::iterator &end);
    unsigned int shortestSpan(void) const;
    unsigned int longestSpan(void) const;

    class ContainerFullException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Container full!";
        }
    };
    class LessThanTwoIntegerException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Container has less than two integer!";
        }
    };
};
