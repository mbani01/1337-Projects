/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:30:22 by mbani             #+#    #+#             */
/*   Updated: 2021/03/03 10:43:58 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template<typename T>
void swap(T & val1, T & val2)
{
    T tmp;
    tmp = val1;
    val1 = val2;
    val2 = tmp;
}

template<typename T>
T min(T val1, T val2)
{
    return (val2 <= val1) ? val2 : val1 ;
}

template<typename T>
T max(T val1, T val2)
{
    return (val2 >= val1) ? val2 : val1;
}

#endif