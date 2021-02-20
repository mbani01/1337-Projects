/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 00:17:59 by mbani             #+#    #+#             */
/*   Updated: 2021/01/11 18:56:38 by mbani            ###   ########.fr       */
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
	size_t f;
	size_t pos = 0;
	f = 0;
	if (rep[2] != rep[3])
	{
		while((f = line.find(rep[2], pos)) != std::string::npos)
		{
			pos = f + 1; 
			line.replace(f, strlen(rep[2]), rep[3]);
		}
	}
}

void opened(std::string name, std::ifstream &file, char **argv)
{
	std::ofstream file1(name);
	std::string line;

	while(getline(file, line) && !file.eof())
	{
		find_rep(line, argv);
		line += '\n';
		file1<<line;
		if (!file1.good())
		{
			std::cout<<"Something bad happened !"<<std::endl;
			file1.close();
			file.close();
			exit (1);
		}
	}
	getline(file, line);
	find_rep(line, argv);
	std::cout<<line;
	file1<<line;
	file1.close();
}

int main(int argc, char **argv)
{
	
	std::ifstream file(argv[1]);
	
	check_arg(argv, argc);
	if(file.is_open())
	{
		opened(((std::string)argv[1] + (".replace")), file, argv);
		file.close();
	}
	else
		std::cout<<"File Not Opened !"<<std::endl;
}