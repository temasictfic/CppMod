/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:21:56 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/25 02:55:41 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include <sstream>

int isDigit(char d)
{
    return (d >= '0' && d <= '9');
}

int whichOperator(char rpn)
{
    std::string ops = "+-*/";
    for (size_t i = 0; i < 4; i++)
    {
        if (rpn == ops[i])
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Where is rpn notation?" << std::endl;
        return -1;
    }
    std::stringstream ss(argv[1]);
    std::string rpn;
    std::list<int> list;
    while (!ss.eof())
    {
        std::getline(ss, rpn, ' ');
        if (rpn.length() == 1 && (isDigit(rpn[0]) || whichOperator(rpn[0]) != -1))
            (isDigit(rpn[0])) ? list.push_back(rpn[0] - 48) : list.push_back(rpn[0]);
        else
            throw std::runtime_error("Error: Non valid character!");
        if (list.size() == 3)
        {
            int o = whichOperator(list.back());
            if (o == -1)
                throw std::runtime_error("Error: Non valid notation arrangement!");
            list.pop_back();
            switch (o)
            {
            case 0:
                list.front() += list.back();
                break;
            case 1:
                list.front() -= list.back();
                break;
            case 2:
                list.front() *= list.back();
                break;
            case 3:
                list.front() /= list.back();
                break;
            }
            list.pop_back();
        }
    }
    std::cout << list.front() << std::endl;
    return 0;
}
