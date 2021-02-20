/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:16:50 by mbani             #+#    #+#             */
/*   Updated: 2021/01/10 15:07:20 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

std::string	Human::identify()
{
	return this->br.identify();
}
const Brain& Human::getBrain()
{
	return	this->br;
}
Human::Human():br(getBrain()){}
Human::~Human(){}