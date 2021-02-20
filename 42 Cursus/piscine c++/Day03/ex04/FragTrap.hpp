/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:23:54 by mbani             #+#    #+#             */
/*   Updated: 2021/02/09 12:19:23 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#ifndef FRAGTRAP_HPP
#define	FRAGTRAP_HPP

class FragTrap :virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string );
	FragTrap(const FragTrap &);
	void operator=(const FragTrap &);
	~FragTrap();
	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const & target);
	void	vaulthunter_dot_exe(std::string const & target);
};



#endif
