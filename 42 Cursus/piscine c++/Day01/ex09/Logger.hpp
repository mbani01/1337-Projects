/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:40:32 by mbani             #+#    #+#             */
/*   Updated: 2021/01/11 18:38:33 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LOGGER_HPP
#define __LOGGER_HPP
#include <iostream>
#include <fstream>
#include <fstream>
#include <ctime>
class Logger
{
private:
	std::string filename;
	void logToConsole(std::string);
	void logToFile(std::string);
	std::string makeLogEntry(std::string);
public:
	void  log(std::string const & dest, std::string const & message);
	Logger();
	~Logger();
};


#endif