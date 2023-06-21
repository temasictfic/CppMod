/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:57:57 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/20 20:58:12 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"
#include <vector>

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    std::vector<int> vec(arr, arr + n);
    /*
        try
        {
            int find = easyFind(arr, 4);
            std::cout << find << std::endl;
            int find2 = easyFind(arr, 9);
            std::cout << find2 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    */
    try
    {
        int find = easyFind(vec, 4);
        std::cout << find << std::endl;
        int find2 = easyFind(vec, 9);
        std::cout << find2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
