/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:30:38 by mbani             #+#    #+#             */
/*   Updated: 2021/01/12 11:04:13 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

void Pony::setpony(const char s[5])
{
	std::cout<<"Enter a value for PonyOnThe"<<s<<": "<<std::endl;
	getline(std::cin, Pony::pony);
}
std::string Pony::getpony()
{
	return pony;
}
Pony::Pony()
{
	
}
Pony::~Pony()
{
	std::cout<<"Pony object destoryed !!"<<std::endl;
}
void ponyOnTheStack()
{
	Pony stk;
	stk.setpony("Stack");
	std::cout<<"Pony is on the stack it's value is : "<<stk.getpony()<<std::endl;
}
void ponyOnTheHeap()
{
	Pony *heap;
	heap = new Pony;
	heap->setpony("Heap");	
	std::cout<<"Pony is on the heap it's value is : "<<heap->getpony()<<std::endl;
	delete heap;
}