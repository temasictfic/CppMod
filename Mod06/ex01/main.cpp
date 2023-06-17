/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 02:18:47 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/18 02:18:48 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

struct Data
{
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    Serializer s;
    Data orig;
    Data *orig_ptr;
    Data *ret_ptr;

    orig.a = 'a';
    orig.b = 'b';
    orig.c = 'c';
    orig.d = 'd';
    orig_ptr = &orig;
    ret_ptr = s.deserialize(s.serialize(orig_ptr));
    std::cout << "pointers are equal: " << (orig_ptr == ret_ptr) << std::endl;

    return 0;
}
