/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 02:18:47 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/18 03:12:48 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

struct Data
{
    size_t s;
};

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    Serializer s;
    Data orig;
    Data *orig_ptr;
    Data *ret_ptr;

    orig.s = 1;
    orig_ptr = &orig;
    ret_ptr = s.deserialize(s.serialize(orig_ptr));
    std::cout << "pointers are equal: " << (orig_ptr == ret_ptr) << std::endl;

    return 0;
}
