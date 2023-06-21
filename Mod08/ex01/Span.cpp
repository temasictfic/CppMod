/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:37:14 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 02:59:52 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int &N) : _size(N) {}

Span::Span(const Span &copy) : _vec(copy._vec), _size(copy._size) {}

Span &Span::operator=(const Span &assign)
{
    _vec = assign._vec;
    _size = assign._size;
    return *this;
}

Span::~Span()
{
    return;
}

void Span::addNumber(int n)
{
    if (_vec.size() < _size)
        _vec.push_back(n);
    else
        throw ContainerFullException();
}

void Span::addNumber(const std::vector<int>::iterator &begin,
                     const std::vector<int>::iterator &end)
{
    int left = (_size - _vec.size());
    if (std::distance(begin, end) > left)
    {
        for (std::vector<int>::iterator it = begin; it != begin + left; it++)
        {
            _vec.push_back(*it);
        }
        //std::cout << _vec.size() << std::endl;
        throw ContainerFullException();
    }
    else
    {
        for (std::vector<int>::iterator it = begin; it != end; it++)
        {
            _vec.push_back(*it);
        }
    }
}

unsigned int Span::shortestSpan() const
{
    if (_size < 2)
        throw LessThanTwoIntegerException();
    std::vector<int> sorted(_vec);

    std::sort(sorted.begin(), sorted.end());
    int prev = *(sorted.begin() + 1);
    int min = prev - sorted.front();
    for (std::vector<int>::iterator it = sorted.begin() + 2; it != sorted.end(); it++)
    {
        if (min > *it - prev)
        {
            min = *it - prev;
        }
        prev = *it;
    }
    return (min);
}

unsigned int Span::longestSpan(void) const
{
    if (_size < 2)
        throw LessThanTwoIntegerException();
    std::vector<int> sorted(_vec);

    std::sort(sorted.begin(), sorted.end());
    return (sorted.back() - sorted.front());
}
