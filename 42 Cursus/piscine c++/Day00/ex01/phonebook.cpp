/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:58:13 by mbani             #+#    #+#             */
/*   Updated: 2021/01/01 17:45:30 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Classcontact.hpp"

contact cnt[8];
static int i;
void add()
{
	if(i < 8)
	cnt[i].fillinfo();
	if(i == 8)
	{
		std::cout<<"You Can't Entre More Than 8 Contacts!"<<std::endl;
		return;
	}
	i++;
}
void	parse(std::string info, int len)
{
	char word[11];
	int sp;
	int i=0;
	int j=0;
	sp = 10 - len;
	while(i < sp)
	{
		word[i]=' ';
		i++;
	}
	sp = 10 - sp;
	while(sp)
	{
		word[i]=info[j];
		j++;
		i++;
		sp--;
	}
	std::cout<<word<<"|";
	
}
void trunc(std::string info)
{
	char word[11];
	int i = 0;
	while (i < 10)
	{
		word[i] = info[i];
		i++;
	}
	word[9] = '.';
	word[10]='\0';
	std::cout<<word<<"|";
}
void	print_info(int in)
{
	std::cout<<"First name: "<<cnt[in].Getfirstname()<<std::endl;
	std::cout<<"Last name: "<<cnt[in].Getlastname()<<std::endl;
	std::cout<<"Nick name: "<<cnt[in].Getnickname()<<std::endl;
	std::cout<<"Login: "<<cnt[in].Getlogin()<<std::endl;
	std::cout<<"Address: "<<cnt[in].Getaddress()<<std::endl;
	std::cout<<"Email address: "<<cnt[in].Getemail()<<std::endl;
	std::cout<<"Phone number: "<<cnt[in].Getphone()<<std::endl;
	std::cout<<"Birthday Date: "<<cnt[in].Getbirth()<<std::endl;
	std::cout<<"Favorite Meal: "<<cnt[in].Getfavmeal()<<std::endl;
	std::cout<<"Underwear Color: "<<cnt[in].Getunderwear()<<std::endl;
	std::cout<<"Darkest Secret: "<<cnt[in].Getsecret()<<std::endl;
}
void print()
{
	int j = 0;
	std::string index;
	int in;
	int len;
	if (i != 0)
	{
		do
		{
			std::cout.width(10);std::cout<<std::right<<j+1<<"|";
			if ((len = cnt[j].Getfirstname().length()) <= 10)
				parse(cnt[j].Getfirstname(), len);
			else
				trunc(cnt[j].Getfirstname());
			if ((len = cnt[j].Getlastname().length()) <= 10)
				parse(cnt[j].Getlastname(), len);
			else
				trunc(cnt[j].Getlastname());
			if ((len = cnt[j].Getnickname().length()) <= 10)
				parse(cnt[j].Getnickname(), len);
			else
				trunc(cnt[j].Getnickname());
			std::cout<<std::endl;
			j++;
		}while(j < i);
		std::cout<<"please choose an index : ";
		getline(std::cin, index);
		in = atoi(index.c_str());
		if(in <= 0 || in > i)
			std::cout<<"ERROR!!"<<std::endl;
		else
			print_info(in - 1);
	}
	return;
}
void search()
{
	std::cout.width(11);std::cout<<std::right<<"index|";
	std::cout.width(11);std::cout<<std::right<<"first name|";
	std::cout.width(11);std::cout<<std::right<<"last name|";
	std::cout.width(11);std::cout<<std::right<<"nickname|"<<std::endl;
	print();
	return;
}
void command(std::string cmd)
{
	if(cmd.compare("EXIT")==0)
		exit(0);
	else if(cmd.compare("ADD")==0)
		add();
	else if(cmd.compare("SEARCH")==0)
		search();
}
int main()
{
	contact fisrt;
	std::string cmd;
	do
	{
		do
		{
			std::cout<<"Please Entre a Command (ADD,SEARCH or EXIT): ";
			getline(std::cin, cmd);
		}while(cmd.compare("EXIT") != 0 && cmd.compare("SEARCH") != 0 && cmd.compare("ADD") != 0);
		command(cmd);
	} while (1);
	
}