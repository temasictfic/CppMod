/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:13:34 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/18 20:21:01 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.tpp"
#include <iostream>

int main(void)
{
    int f = 2;
    int s = 3;
    float a = 5.0;
    float b = 6.0;
    char x = 'x';
    char y = 'y';

    std::cout << "swap" << std::endl;
    swap<int>(f, s);
    std::cout << f << " " << s << std::endl;
    swap(a, b);
    std::cout.precision(2);
    std::cout << std::showpoint << a << " " << b << std::endl;
    swap<>(x, y);
    std::cout << x << " " << y << std::endl;

    std::cout << "max" << std::endl;
    std::cout << max<int>(f, s) << std::endl;
    std::cout.precision(2);
    std::cout << std::showpoint << max(a, b) << std::endl;
    std::cout << max<>(x, y) << std::endl;

    std::cout << "min" << std::endl;
    std::cout << min<int>(f, s) << std::endl;
    std::cout.precision(2);
    std::cout << std::showpoint << min(a, b) << std::endl;
    std::cout << min<>(x, y) << std::endl;

    return 0;
}
