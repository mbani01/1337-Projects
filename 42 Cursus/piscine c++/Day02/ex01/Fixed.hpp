/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:56:47 by mbani             #+#    #+#             */
/*   Updated: 2021/02/05 17:26:20 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_CLASS
#define __FIXED_CLASS
#include <iostream>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &);
        Fixed(const int nbr);
        Fixed(const float nbr);
        ~Fixed();
        void operator=(const Fixed &);
        float getRawBits(void)const ;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};
std::ostream &operator<<(std::ostream& out, Fixed const &obj);

#endif