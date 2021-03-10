/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:19:56 by mbani             #+#    #+#             */
/*   Updated: 2021/03/02 10:39:39 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void print_to_char(char c);
void print_int(long i);
void print_float(long double lg);
void print_double(long double lg);

void convert_char_int(const char *nptr, char *endptr)
{
    long integer = strtol(nptr, &endptr, 10);
    if (nptr == endptr)
    {
        std::cout << "char: impossible" << std::endl;   
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        print_to_char(integer);
        print_int(integer);
    }
}

void convert_double_float(const char *arg)
{
    long double dbl;
    try 
    {
        dbl = std::stold(arg);
        print_float(dbl);
    }
    catch(std::exception &e)
    {
        std::cout << "float: nanf" << std::endl;
    }
    try
    {
        dbl = std::stold(arg);
        print_double(dbl);
    }
    catch(const std::exception& e)
    {
        std::cout << "double: nanf" << std::endl;
    }
}
