/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classcontact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:06:31 by mbani             #+#    #+#             */
/*   Updated: 2020/04/14 17:32:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classcontact.hpp"

void contact::fillinfo()
{
	std::cout<<"Entre first name: ";
	std::cin>>first_name;
	std::cout<<"Entre last_name: ";
	std::cin>>last_name;
	std::cout<<"Entre nick_name: ";
	std::cin>>nick_name;
	std::cout<<"Entre login: ";
	std::cin>>login;
	std::cout<<"Entre postal_add: ";
	std::cin>>postal_add;;
	std::cout<<"Entre email: ";
	std::cin>>email;
	std::cout<<"Entre phone_number: ";
	std::cin>>phone_num;
	std::cout<<"Entre birth_date: ";
	std::cin>>birth_date;
	std::cout<<"Entre favorite_meal: ";
	std::cin>>favorite_meal;
	std::cout<<"Entre underwear_color: ";
	std::cin>>underwear_color;
	std::cout<<"Entre darkest_secret: ";
	std::cin>>darkest_secret;
	return;
}
std::string contact::Getfirstname()
{
	return first_name;
}
std::string contact::Getlastname()
{
	return last_name;
}
std::string contact::Getnickname()
{
	return nick_name;
}
std::string contact::Getlogin()
{
	return login;
}
std::string contact::Getaddress()
{
	return postal_add;
}
std::string contact::Getemail()
{
	return email;
}
std::string contact::Getphone()
{
	return phone_num;
}
std::string contact::Getbirth()
{
	return birth_date;
}
std::string contact::Getfavmeal()
{
	return favorite_meal;
}
std::string contact::Getunderwear()
{
	return underwear_color;
}
std::string contact::Getsecret()
{
	return darkest_secret;
}