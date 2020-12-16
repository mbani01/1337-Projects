/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 00:10:06 by mbani             #+#    #+#             */
/*   Updated: 2020/04/19 00:19:47 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain;
	std::string &ref=brain;
	std::string *ptr=&brain;

	brain = "HI THIS IS BRAIN";
	std::cout<<"by reference :"<<ref<<std::endl;
	std::cout<<"by pointer :"<<*ptr<<std::endl;
	
}