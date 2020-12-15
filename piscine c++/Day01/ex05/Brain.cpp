/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 02:47:04 by mbani             #+#    #+#             */
/*   Updated: 2020/04/21 16:45:10 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

std::string	Brain::identify()
{
	int j;
	std::string res;
	char c;
	res += add_to_str(((long)&(this->brain)));
	j = res.length()-1;
	for(int i=0; i < j/2; i++)
	{
		c = res[i];
		res[i] = res[j];
		res[j] = c;
		j--;
	}
	res = "0x" + res;
	return res;
}

std::string Brain::add_to_str(long x)
{
  	long quot;
	long rem;
	std::string res;
	
	quot=x;
	while(quot!=0)
	{
		(rem=quot%16) < 10 ? res+=(rem+48) : res+=(rem+87);
		quot/=16;
	}
	return res;
}
