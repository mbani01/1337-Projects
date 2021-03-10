/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:03:40 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 14:49:47 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern &obj)
{
    *this = obj;
}

void Intern::operator=(const Intern &obj)
{
    (void)obj;
}

Form* Intern::makeForm(std::string form, std::string target)
{
    
    Form *inv[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    for(int i = 0 ; i < 3; i++)
    {
        if (form.compare(inv[i]->getName()) == 0)
        {
            for(int j = 0 ; j < 3; j++)
                if (j != i)
                    delete inv[j];
            std::cout << "Intern creates " << inv[i]->getName() << std::endl;
            return inv[i];
        }
    }
    std::cout << "The requested Form is not known!!" << std::endl;
    return nullptr;
}

Intern::~Intern()
{
}
