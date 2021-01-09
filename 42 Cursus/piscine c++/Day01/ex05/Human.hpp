/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 23:12:15 by mbani             #+#    #+#             */
/*   Updated: 2021/01/09 18:45:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_HPP
#define __HUMAN_HPP
#include <iostream>
#include "Brain.hpp"

class Human
{
	private:
		const Brain br;
	public:
		Human();
		const Brain &getBrain();
		std::string	identify();
};

#endif