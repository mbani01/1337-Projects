/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:58:13 by mbani             #+#    #+#             */
/*   Updated: 2020/04/11 21:30:36 by mbani            ###   ########.fr       */
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
	char word[10];
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
	char word[10];
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
}
void print()
{
	int j=0;
	int in;
	int len;
	if (i != 0)
	{
	do
	{
		std::cout<<"         "<<j+1<<"|";
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
	do
	{
		std::cout<<"please choose an index : ";
		std::cin>>in;
		if (std::cin.fail())
		{
			std::cout<<"Error !!"<<std::endl;
			std::cin.clear();
        	std::cin.ignore();
		}
		if(in <= 0 || in > i)
			std::cout<<"Try again!!"<<std::endl;
	} while (in <= 0 || in > i);
	print_info(in-1);
	}
	return;
}
void search()
{
	std::cout<<"     index|first name| last name|  nickname|"<<std::endl;
	print();
	return;
}
void command(std::string cmd)
{
	if(cmd.compare("exit")==0)
		exit(0);
	else if(cmd.compare("add")==0)
	add();
	else if(cmd.compare("search")==0)
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
		std::cout<<"Please Entre a Command (add,search or exit): ";
	std::cin>>cmd;
	}while(cmd.compare("exit") != 0 && cmd.compare("search") != 0 && cmd.compare("add") != 0);
	command(cmd);
	} while (1);
	
}