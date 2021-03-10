/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:44:57 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 11:26:25 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static int i;
    i++;
    if (!(executor.getGrade() <= this->getGradeToExecute()  && this->getSignature()))
        throw NotExecutableException();
    else
    {
        if (i % 2)
        {
            std::cout << "Derrrrrrrrrrrrrrr Derrrrrrrrrrrrrrr "<< this->_target << " has been robotomized successfully !"  << std::endl;    }
        else
            std::cout << "Failed to robotomize " << this->_target << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):Form(obj.getName(), obj.getGradeToBeSigned(), obj.getGradeToExecute())
{
    *this = obj;
}

void RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    this->setSignature(obj.getSignature());
    this->_target = obj._target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}