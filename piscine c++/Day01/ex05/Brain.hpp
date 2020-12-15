/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 02:47:29 by mbani             #+#    #+#             */
/*   Updated: 2020/04/21 02:46:33 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Brain{
	private:
		int brain;
	public:
		
		std::string	identify();
		std::string	add_to_str(long x);
};