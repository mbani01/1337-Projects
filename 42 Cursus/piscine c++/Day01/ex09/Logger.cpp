/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:49:04 by mbani             #+#    #+#             */
/*   Updated: 2021/01/11 18:44:21 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

void	Logger::logToFile(std::string str)
{
	this->filename = "logfile.log";
	std::ofstream file;
	file.open("logfile.log", std::ios_base::app);
	if (file.is_open())
		file<<str<<std::endl;
	else
		std::cout<<"Error !!!"<<std::endl;
	file.close();
}

void	Logger::logToConsole(std::string str)
{
	std::cout<<str<<std::endl;
}

std::string Logger::makeLogEntry(std::string str)
{
	time_t now = time(0);
	char* dt = ctime(&now);
	std::string str1;
	str1.append("[");
	str1.append(dt);
	str1.pop_back();
	str1.append("]");
	str1.append(": ");
	str1.append(str);
	return str1;
}

void	Logger::log(std::string const & dest, std::string const & message)
{
	const std::string dst[2] = {"logToConsole", "logToFile"};
	void (Logger::*ptr[2]) (std::string );

	ptr[0] = &Logger::logToConsole;
	ptr[1] = &Logger::logToFile;
	for(int i = 0;i < 2;i++)
		if(dst[i].compare(dest) == 0)
		{
			(this->*ptr[i]) (makeLogEntry(message));
		}
}
Logger::Logger()
{
}

Logger::~Logger()
{
}