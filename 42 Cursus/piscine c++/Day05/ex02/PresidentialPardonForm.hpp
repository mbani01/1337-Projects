/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:40:19 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 14:39:38 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM__HPP
#define PRESIDENTIALPARDONFORM__HPP
#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm ();
        PresidentialPardonForm (std::string );
        PresidentialPardonForm (const PresidentialPardonForm &);
        void operator=(const PresidentialPardonForm &);
        void  execute(Bureaucrat const & executor) const;
        virtual ~PresidentialPardonForm ();
};


#endif