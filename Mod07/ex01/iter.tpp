/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter..tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:02:42 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/18 22:32:24 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <typename A>
void iter(A *arr, size_t const &len, void (*func)(A &))
{
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

template <typename T>
void addSelf(T &value)
{
    value += value;
}
