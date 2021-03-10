/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:07:51 by mbani             #+#    #+#             */
/*   Updated: 2021/02/24 11:06:34 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    int grade = 3;
    try 
    {
        Bureaucrat inst("mbani", grade);
        inst.incrementGrade();
        std::cout << inst;
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }
    grade = 150;
    try 
    {
        Bureaucrat inst1("mamoussa", grade);
        std::cout << inst1;
        inst1.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }
    grade = -10;
    try 
    {
        Bureaucrat inst2("zel-bagh", grade);
        std::cout << inst2;
    }
    catch (std::exception & e)
    {
        std::cout <<e.what()<< std::endl;
    }

}