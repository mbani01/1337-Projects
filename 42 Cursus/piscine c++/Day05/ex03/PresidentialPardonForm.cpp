/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:03:06 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 11:21:05 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm ::PresidentialPardonForm (std::string target): Form("presidential pardon", 25, 5), _target(target)
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!(executor.getGrade() <= this->getGradeToExecute()  && this->getSignature()))
        throw NotExecutableException();
    else
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):Form(obj.getName(), obj.getGradeToBeSigned(), obj.getGradeToExecute())
{
    *this = obj;
}

void PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    this->setSignature(obj.getSignature());
    this->_target = obj._target;
}

PresidentialPardonForm ::~PresidentialPardonForm ()
{
}
