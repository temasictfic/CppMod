/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 02:29:41 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/18 03:08:23 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
    // Set Seed
    srand((unsigned)time(NULL));
    int i = rand() % 3;
    std::cout << "generated "
              << "ABC"[i] << std::endl;
    switch (i)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    default:
        return new C();
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "pointer to object of type: A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "pointer to object of type: B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "pointer to object of type: C" << std::endl;
    else
        std::cerr << "bad cast" << std::endl;
}

void identify(Base &p)
{
    try
    {
        if (dynamic_cast<A *>(&p) != NULL)
            std::cout << "reference to object of type: A" << std::endl;
        else if (dynamic_cast<B *>(&p) != NULL)
            std::cout << "reference to object of type: B" << std::endl;
        else if (dynamic_cast<C *>(&p) != NULL)
            std::cout << "reference to object of type: C" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    Base *ptr = generate();
    Base &ref = *ptr;

    /*
    class M
    {
    public:
        M(){}
        ~M(){}
    };
    M* mptr = new M();
    Base *ptre = dynamic_cast<M *>(mptr); //not allowed!
    */

    identify(ptr);
    std::cout << "--------------------" << std::endl;
    identify(ref);

    delete ptr;
    return 0;
}
