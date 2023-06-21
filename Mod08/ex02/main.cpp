/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 03:24:26 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 03:31:11 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"

int main(void)
{
    MutantStack<int> mstack;
    mstack.push(17);
    mstack.push(5);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(7);
    std::cout << "__________mstack_________" << std::endl;
    for (MutantStack<int>::iterator it = mstack.end() - 1; it != mstack.begin() - 1; it--)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}
