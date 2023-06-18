/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:02:35 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/19 01:53:31 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.tpp"
#include <iostream>

int main(void)
{
    int arr[] = {1, 2, 3, 4};
    float arr2[] = {1., 2., 3., 4.};
    size_t len = sizeof(arr) / sizeof(int);
    size_t len2 = sizeof(arr2) / sizeof(float);

    iter(arr, len, addSelf);
    for (size_t i = 0; i < len; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    iter(arr2, len2, addSelf);
    for (size_t i = 0; i < len2; i++)
    {
        std::cout << std::showpoint << arr2[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
