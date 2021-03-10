/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:07:51 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 15:09:39 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    int grade = 10;
    int required_grade = 50;
    try
    {
        Form frm("Passeport", required_grade, grade);
        Bureaucrat inst("mbani", grade);
        std::cout << inst << frm;
        frm.beSigned(inst);
        std::cout << frm;
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }
    std::cout << std::endl;
    grade = 100;
    required_grade = 3;
    Form frm1("National ID", required_grade, grade);
    try 
    {
        Bureaucrat inst2("mamoussa", grade);
        std::cout << inst2 << frm1;
        frm1.beSigned(inst2);
        std::cout << frm1;
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }
}