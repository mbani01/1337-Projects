/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:23:54 by mbani             #+#    #+#             */
/*   Updated: 2020/09/26 23:40:29 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#ifndef FRAGTRAP_HPP
#define	FRAGTRAP_HPP

class FragTrap : public ClapTrap
{

public:
	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const & target);
	void	vaulthunter_dot_exe(std::string const & target);
	FragTrap(std::string );
	~FragTrap();
};



#endif
