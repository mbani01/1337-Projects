/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classcontact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:32:19 by mbani             #+#    #+#             */
/*   Updated: 2020/04/11 21:11:17 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCONTACT_HPP
#define CLASSCONTACT_HPP
#include <string>
#include <iostream>
class contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string login;
	std::string postal_add;
	std::string email;
	std::string phone_num;
	std::string birth_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
public:
	void fillinfo();
	std::string Getfirstname();
	std::string Getlastname();
	std::string Getnickname();
	std::string Getlogin();
	std::string Getaddress();
	std::string Getemail();
	std::string Getphone();
	std::string Getbirth();
	std::string Getfavmeal();
	std::string Getunderwear();
	std::string Getsecret();
	
};

#endif
