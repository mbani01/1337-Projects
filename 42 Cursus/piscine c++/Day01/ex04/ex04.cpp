/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 00:10:06 by mbani             #+#    #+#             */
/*   Updated: 2021/01/09 17:10:23 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain;
	brain = "HI THIS IS BRAIN";

	std::string &ref=brain;
	std::string *ptr=&brain;
	std::cout<<"By Pointer :"<<*ptr<<std::endl;
	std::cout<<"By Reference :"<<ref<<std::endl;
	
}