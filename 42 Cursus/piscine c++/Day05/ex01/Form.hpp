/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:41:13 by mbani             #+#    #+#             */
/*   Updated: 2021/02/24 11:12:54 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _GradeToBeSigned;
        const int _GradeToExecute;
    public:
        Form();
        Form(const Form &);
        void operator=(const Form &);
        Form(const std::string &, const int &, const int &);
        class GradeTooHighException : public std::exception
        {
            const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char * what() const throw();
        };
        const std::string & getName() const;
        bool getSignature() const;
        const int & getGradeToBeSigned() const;
        const int & getGradeToExecute() const;
        void beSigned(Bureaucrat const &);
        ~Form();
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif