/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 23:12:15 by mbani             #+#    #+#             */
/*   Updated: 2021/01/10 15:05:45 by mbani            ###   ########.fr       */
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
		~Human();
		const Brain &getBrain();
		std::string	identify();
};

#endif