/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 03:50:12 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/05 03:50:13 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
    std::string _name;
    Weapon& _wpA;
public:
    HumanA(std::string name, Weapon& wp);
    ~HumanA();
    void    setWeapon(Weapon& wp);
    void attack() const;
};

