
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
		std::string pony;
	public:
		void setpony(const char s[5]);
		std::string getpony();
		Pony();
		~Pony();
};
void ponyOnTheHeap();
void ponyOnTheStack();
#endif