/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 03:50:05 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/05 17:42:19 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
    std::string _name;
    Weapon *_wpB;

public:
    HumanB(std::string name);
    ~HumanB();
    void setWeapon(Weapon &wp);
    void attack() const;
};
