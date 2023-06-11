/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:13:41 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/11 22:33:23 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "DefaultTarget", 145, 137)
{
    return;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
    this->AForm::operator=(assign);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return;
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &executor) const
{

    std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());

    if (!ofs.is_open() || ofs.fail())
    {
        std::cerr << "Shrubbery creation has failed!" << std::endl;
        throw std::ofstream::failure(strerror(errno));
    }
    else
    {
        ofs << TREE;
        ofs.close();
        std::cout << executor.getName() << " successfully created a shrubbery" << std::endl;
    }
}
