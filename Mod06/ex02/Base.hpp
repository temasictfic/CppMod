/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 02:29:43 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/18 02:29:59 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
public:
    Base(/* args */) {}
    virtual ~Base() {}
};

class A : public Base
{
public:
    A(/* args */) {}
    ~A() {}
};

class B : public Base
{
public:
    B(/* args */) {}
    ~B() {}
};

class C : public Base
{
public:
    C(/* args */) {}
    ~C() {}
};
