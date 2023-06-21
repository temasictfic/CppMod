/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:21:56 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/22 01:21:57 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
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
    std::deque<int> dq;
    while (!ss.eof())
    {
        std::getline(ss, rpn, ' ');
        if (rpn.length() == 1 && (isDigit(rpn[0]) || whichOperator(rpn[0]) != -1))
            (isDigit(rpn[0])) ? dq.push_back(rpn[0] - 48) : dq.push_back(rpn[0]);
        else
            throw std::runtime_error("Error: Non valid character!");
        if (dq.size() == 3)
        {
            int o = whichOperator(dq.back());
            if (o == -1)
                throw std::runtime_error("Error: Non valid notation arrangement!");
            dq.pop_back();
            switch (o)
            {
            case 0:
                dq.front() += dq.back();
                break;
            case 1:
                dq.front() -= dq.back();
                break;
            case 2:
                dq.front() *= dq.back();
                break;
            case 3:
                dq.front() /= dq.back();
                break;
            }
            dq.pop_back();
        }
    }
    std::cout << dq.front() << std::endl;
    return 0;
}
