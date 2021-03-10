/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:16:37 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 11:22:45 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form("shrubbery creation", 145, 137), _target(target)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename, std::ofstream::out);
    if (!(executor.getGrade() <= this->getGradeToExecute()  && this->getSignature()))
        throw NotExecutableException();
    else
    {
        std::string asci_tree = "       ****\n     ********\n    **  ******\n     *   ******     ******\n         ******   *********\n          ****  *****   ***\n          ***  ***     **\n    *************       *\n  ******************\n *****   H****H*******\n ***     H-__-H  *********\n  ***    H    H      *******\n   **    H-__-H        *****\n     *   H    H         ****\n         H    H         ***\n         H-__-H         **\n         H    H         *\n         H-__-H\n";
        file << asci_tree;
        file.close();
    }
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj):Form(obj.getName(), obj.getGradeToBeSigned(), obj.getGradeToExecute())
{
    *this = obj;
}

void ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    this->setSignature(obj.getSignature());
    this->_target = obj._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
