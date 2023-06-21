/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:59:41 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 03:31:14 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack(void) : std::stack<T>() {}
	MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
	~MutantStack(void) {}

	MutantStack &operator=(const MutantStack &assign)
	{
		this->c = assign.c;
		return *this;
	}

	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }
};
