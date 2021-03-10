/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:31:21 by mbani             #+#    #+#             */
/*   Updated: 2021/03/02 10:32:47 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <math.h>

void print_to_char(char c)
{
    if (isprint(static_cast<int>(c)))
        std::cout << "char: \'" << (c) << "\'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;
}

void print_int(long i)
{

    if (i >= INT_MIN && i <= INT_MAX)
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void print_float(long double lg)
{
    if ((lg) != (lg))
        std::cout << "float: nanf" << std::endl;
    else if (lg > std::numeric_limits<float>::max())
        std::cout << "float: +inff" << std::endl;
    else if (lg < std::numeric_limits<float>::lowest() && lg != 0)
        std::cout << "float: -inff" << std::endl;
    else
    {
        if (static_cast<float>(lg) == static_cast<int>(lg))
            std::cout << "float: " << static_cast<float>(lg) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(lg) << std::endl;
    }
}
void print_double(long double lg)
{

    if (lg > std::numeric_limits<double>::max())
        std::cout << "double: +inf" << std::endl;
    else if ((lg) < std::numeric_limits<double>::lowest())
        std::cout << "double: -inf" << std::endl;
    else
    {
        if (static_cast<double>(lg) == static_cast<int>(lg))
            std::cout << "double: " << static_cast<double>(lg) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(lg) << std::endl;
    }
}
