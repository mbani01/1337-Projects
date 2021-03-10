/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:07:51 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 09:44:48 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    int grade = 72;
    Intern someRandomIntern;
    Form* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    try
    {
        Bureaucrat inst("mbani", grade);
        if (rrf)
        {
            rrf->beSigned(inst);
            std::cout << *rrf;
            inst.executeForm(*rrf);//grade is not enough to execute this form;
        }
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }
    std::cout << std::endl;
    Form* rrf1;
    rrf1 = someRandomIntern.makeForm("shrubbery creation", "home");
    try
    {
        Bureaucrat inst2("mamoussa", grade);
        if (rrf1)
        {
            rrf1->beSigned(inst2);
            std::cout << *rrf1;
            inst2.executeForm(*rrf1);//the from will be executed successfully
        }
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }

    std::cout << std::endl;
    Form* rrf2;
    rrf2 = someRandomIntern.makeForm("unknown", "someone"); // an unknown form 
    try
    {
        Bureaucrat inst2("ismail", grade);
        if (rrf2)
        {
            rrf2->beSigned(inst2);
            std::cout << *rrf2;
            inst2.executeForm(*rrf2);
        }
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }
    
}