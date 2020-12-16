/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 00:55:27 by mbani             #+#    #+#             */
/*   Updated: 2020/04/15 23:09:38 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void memoryLeak()
{
std::string* panthere = new std::string("String panthere");
std::cout << *panthere << std::endl;
delete panthere;
}
int main()
{
	memoryLeak();
}