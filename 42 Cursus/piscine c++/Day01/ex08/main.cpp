/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 23:46:20 by mbani             #+#    #+#             */
/*   Updated: 2021/01/11 18:08:57 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	Human H;
	H.action("meleeAttack", "nobody");
	H.action("rangedAttack", "mbani");
	H.action("intimidatingShout", "you");
}