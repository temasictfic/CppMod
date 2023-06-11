/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:53:01 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/11 22:46:32 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "DefaultTarget", 72, 45)
{
    return;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", target, 72, 45)
{
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
    return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
    this->AForm::operator=(assign);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return;
}

void RobotomyRequestForm::beExecuted(const Bureaucrat &executor) const
{
    (void)executor;
    std::cout << "Makes some drilling noises" << std::endl;
    // Set Seed
    srand((unsigned)time(NULL));
    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
}
