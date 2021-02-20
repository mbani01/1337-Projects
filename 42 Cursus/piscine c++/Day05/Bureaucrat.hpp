/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:43:35 by mbani             #+#    #+#             */
/*   Updated: 2021/02/19 10:16:25 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat(std::string const &, int &);
    ~Bureaucrat();
};

Bureaucrat::Bureaucrat(std::string const name, int & grade)
{
    this->_name = name;
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}


#endif