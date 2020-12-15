/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:40:32 by mbani             #+#    #+#             */
/*   Updated: 2020/05/02 15:44:26 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Logger::Logger()
{
}

Logger::~Logger()
{
}
