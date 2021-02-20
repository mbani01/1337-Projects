/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:32:53 by mbani             #+#    #+#             */
/*   Updated: 2021/01/11 18:40:57 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main()
{
	Logger l;
	std::string msg = "Hello File log";
	std::string dst = "logToFile";
	std::string msg1 = "Hello console Log";
	std::string dst1 = "logToConsole";
	l.log(dst, msg);
	l.log(dst1, msg1);
}