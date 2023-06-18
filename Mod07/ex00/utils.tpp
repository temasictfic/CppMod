/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:13:27 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/18 20:16:07 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &f, T &s)
{
    T tmp = f;
    f = s;
    s = tmp;
}

template <typename T>
T const &max(T const &f, T const &s)
{
    return (s >= f) ? s : f;
}

template <typename T>
T const &min(T const &f, T const &s)
{
    return (s <= f) ? s : f;
}
