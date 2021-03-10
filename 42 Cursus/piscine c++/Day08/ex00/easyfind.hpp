/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:07:40 by mbani             #+#    #+#             */
/*   Updated: 2021/03/06 10:37:59 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>

template<typename T>
int easyfind(T cnt, int val)
{   
    return (find(cnt.begin(), cnt.end(), val) == cnt.end() ? throw std::exception() : *(find(cnt.begin(), cnt.end(), val)));
}

#endif