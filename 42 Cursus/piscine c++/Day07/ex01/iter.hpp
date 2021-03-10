/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:59:04 by mbani             #+#    #+#             */
/*   Updated: 2021/03/03 12:10:17 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T1>
void iter(T1 * add, int len, void (*foo)(T1 const &))
{
    for(int i = 0; i < len ; i++)
    {
        foo(add[i]);
    }
}
#endif