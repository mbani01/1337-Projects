/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 00:17:59 by mbani             #+#    #+#             */
/*   Updated: 2020/04/27 16:28:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

void check_arg(char **line, int argc)
{
	if (argc != 4 || line[2][0] == '\0' || line[3][0] == '\0')
	{
		std::cout<<"Error please enter : \"FILENAME\" \"STRING1\" \"STRING2\""<<std::endl;
		exit(1);
	}
}

void find_rep(std::string &line, char **rep)
{
	int f;

	f = 0;
	while((f = line.find(rep[2])) != std::string::npos)
	{
		line.replace(f, strlen(rep[2]), rep[3]);
	}
}

void opened(std::string name, std::istream &file, char **argv)
{
	std::ofstream file1(name);
	std::string line;

	while(getline(file, line) && !file.eof())
	{
		find_rep(line, argv);
		line+= '\n';
		file1<<line;
		if (!file1.good())
		{
			std::cout<<"Something bad happened !";
			exit (1);
		}
		
	}
	getline(file, line);
	find_rep(line, argv);
	file1<<line;
}

int main(int argc, char **argv)
{
	
	std::ifstream file(argv[1]);
	
	check_arg(argv, argc);
	if(file.is_open())
		opened(((std::string)argv[1] + (".REPLACE")), file, argv);
	else
		std::cout<<"File Not Opened !"<<std::endl;
}