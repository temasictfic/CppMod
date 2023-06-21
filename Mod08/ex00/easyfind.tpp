/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:58:03 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/20 20:58:06 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
int easyFind(T &container, int wanted)
{
    typename T::iterator pos;

    pos = std::find(container.begin(), container.end(), wanted);

    return (pos != container.end()) ? *pos : throw std::runtime_error("Can't find element in container!");
}
