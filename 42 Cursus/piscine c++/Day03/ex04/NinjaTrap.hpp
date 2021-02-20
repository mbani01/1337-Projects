/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 00:55:33 by mbani             #+#    #+#             */
/*   Updated: 2021/02/09 12:15:57 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#ifndef _NINJATRAP_HPP
#define _NINJATRAP_HPP
class NinjaTrap :virtual public ClapTrap
{

public:
	NinjaTrap();
	NinjaTrap (std::string );
	NinjaTrap(const NinjaTrap &);
	void operator=(const NinjaTrap &);
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const & target);
	void ninjaShoebox(const FragTrap &obj) const;
	void ninjaShoebox(const ScavTrap &obj) const;
	void ninjaShoebox(const NinjaTrap &obj) const;
	~NinjaTrap ();
};



#endif