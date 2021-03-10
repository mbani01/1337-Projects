/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:07:51 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 11:47:00 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    int grade = 137;
    int required_grade = 50;
    ShrubberyCreationForm frm_SH("mbani");
    RobotomyRequestForm rbt("mamoussa");
    PresidentialPardonForm pr("mbani");
    
    try
    {
        Bureaucrat inst("mbani", grade);
        frm_SH.beSigned(inst);
        std::cout << frm_SH;
        inst.executeForm(frm_SH);
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }
    
    std::cout << std::endl;
    grade = 150;
    required_grade = 3;
    try 
    {
        Bureaucrat inst2("mamoussa", grade);
        inst2.signForm(rbt);
        inst2.executeForm(rbt);
        std::cout << rbt;
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }
    std::cout << std::endl;
    grade = 6;
    try
    {
        Bureaucrat inst2("bourki", grade);
        inst2.signForm(pr);
        std::cout << pr;
        inst2.executeForm(pr);
        inst2.incrementGrade();
        inst2.executeForm(pr);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}