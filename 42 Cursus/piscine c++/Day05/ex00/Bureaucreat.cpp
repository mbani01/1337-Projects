/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucreat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:07:22 by mbani             #+#    #+#             */
/*   Updated: 2021/02/24 08:25:59 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    *this = obj;
}

void Bureaucrat::operator=(const Bureaucrat &obj)
{
    this->_grade = obj._grade;
}

Bureaucrat::Bureaucrat(const std::string &name, int & grade):_name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const std::string & Bureaucrat::getName()const
{
    return this->_name;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade += 1;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
            throw Bureaucrat::GradeTooLowException();
    else 
        this->_grade -= 1;
}

int Bureaucrat::getGrade()const
{
    return this->_grade;
}

Bureaucrat::~Bureaucrat()
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "The Grade is too High !!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "The Grade is too Low !!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucreat grade " << obj.getGrade() << std::endl;
    return out;
}