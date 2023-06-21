/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:38:06 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 02:40:29 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(12);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Span sp2 = Span(1);
    try
    {
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    Span sp3 = Span(10000);
    std::vector<int> v;
    for (size_t i = 0; i < 10200; i++)
    {
        v.push_back(std::rand() % INT_MAX);
    }
    try
    {
        sp3.addNumber(v.begin(), v.end());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
    return 0;
}
