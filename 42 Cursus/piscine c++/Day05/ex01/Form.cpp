/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:08:57 by mbani             #+#    #+#             */
/*   Updated: 2021/02/26 15:08:17 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string & name, const int & gradetobesigned, const int & gradetoexecute): _name (name), _GradeToBeSigned(gradetobesigned), _GradeToExecute(gradetoexecute)
{
    if (gradetobesigned > 150 || gradetoexecute > 150)
        throw Form::GradeTooLowException();
    if (gradetoexecute < 1 || gradetoexecute < 1)
        throw Form::GradeTooHighException();
    this->_signed = false;
}

Form::Form(const Form &obj): _name(obj._name), _GradeToBeSigned(obj._GradeToBeSigned), _GradeToExecute(obj._GradeToExecute)
{
    *this = obj;
}

void Form::operator=(const Form &obj)
{
    this->_signed = obj._signed;
}

Form::~Form()
{
}

const std::string & Form::getName()const
{
    return this->_name;
}

bool    Form::getSignature() const
{
    return this->_signed;
}

const int & Form::getGradeToBeSigned() const
{
    return this->_GradeToBeSigned;
}

const int & Form::getGradeToExecute() const
{
    return this->_GradeToExecute;
}

void Form::beSigned(Bureaucrat const &obj)
{
    if (obj.getGrade() > this->_GradeToBeSigned)
        {
            this->_signed = false;
            throw Form::GradeTooLowException();
        }
    else
        this->_signed = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "The grade is too High!!";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "The grade is too Low!!";
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    if (obj.getSignature())
        out << obj.getName() << " requires grade " << obj.getGradeToBeSigned() << " to be signed and grade " << obj.getGradeToExecute() << " To be executed. It's Signed succesfully" << std::endl;
    else
        out << obj.getName() << " requires grade " << obj.getGradeToBeSigned() << " to be signed and grade " << obj.getGradeToExecute() << " To be executed. It's Not Signed" << std::endl;
    return out;
}