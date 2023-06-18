/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:26:13 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/19 01:52:40 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include <iostream>

int main(void)
{
    Array<int> i = Array<int>();
    try
    {
        std::cout << i[0] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "i   : " << i << std::endl;
    Array<int> *a = new Array<int>();
    Array<int> *b = new Array<int>(10);
    std::cout << "b   : " << *b << std::endl;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    memcpy(b->getArr(), arr, 10 * sizeof(int));

    std::cout << "a   : " << *a << std::endl;
    std::cout << "b   : " << *b << std::endl;

    // copy
    Array<int> copy = Array<int>(*b);
    std::cout << "copy: " << copy << std::endl;

    std::cout << "copy address: " << &copy << std::endl;
    std::cout << "b address   : " << b << std::endl;

    // assign
    std::cout << "a address   : " << a << std::endl;
    *a = copy;
    std::cout << "a address   : " << a << std::endl;
    std::cout << "copy address: " << &copy << std::endl;
    std::cout << "a   : " << *a << std::endl;

    std::cout << "copy size: " << copy.size() << std::endl;
    try
    {
        std::cout << "copy[2]  : " << copy[9] << std::endl;
        std::cout << "copy[10] : " << copy[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    Array<float> *c = new Array<float>();
    Array<float> *d = new Array<float>(10);
    float arr2[] = {0., 1., 2., 3., 4., 5., 6., 7., 8., 9.};
    memcpy(d->getArr(), arr2, 10 * sizeof(float));

    std::cout << "c    : " << *c << std::endl;
    std::cout << "d    : " << std::showpoint << *d << std::endl;

    // copy
    Array<float> copy2 = Array<float>(*d);
    std::cout << "copy2: " << std::showpoint << copy2 << std::endl;

    // assign
    *c = copy2;
    std::cout << "c    : " << std::showpoint << *c << std::endl;

    std::cout << "copy2 size: " << copy2.size() << std::endl;
    try
    {
        std::cout << "copy2[2]  : " << copy2[9] << std::endl;
        std::cout << "copy2[10] : " << copy2[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
