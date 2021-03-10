/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:21:28 by mbani             #+#    #+#             */
/*   Updated: 2021/03/02 16:22:27 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEREIALIZE_HPP
#define SEREIALIZE_HPP
#include <iostream>

struct Data
{
   std::string s1;
   int n;
   std::string s2;
};
void * serialize(void);
Data *deserialize(void *raw);

#endif