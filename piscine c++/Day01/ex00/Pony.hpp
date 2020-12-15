
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phony.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:00:20 by mbani             #+#    #+#             */
/*   Updated: 2020/04/14 18:01:21 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

class Pony{
	private:
		int pony;
	public:
		void setpony(const char s[5]);
		int getpony();
		// Pony();
		~Pony();
};
void ponyOnTheHeap();
void ponyOnTheStack();
#endif