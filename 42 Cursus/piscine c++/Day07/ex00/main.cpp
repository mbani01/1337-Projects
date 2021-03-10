/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:38:43 by mbani             #+#    #+#             */
/*   Updated: 2021/03/05 15:16:10 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

class Awesome {
    public:
    Awesome(int n) : _n(n){}

    bool operator==(Awesome const &rhs){return (this->_n == rhs._n);}
    bool operator!=(Awesome const &rhs){return (this->_n != rhs._n);}
    bool operator>(Awesome const &rhs){return (this->_n > rhs._n);}
    bool operator<(Awesome const &rhs){return (this->_n < rhs._n);}
    bool operator>=(Awesome const &rhs){return (this->_n >= rhs._n);}
    bool operator<=(Awesome const &rhs){return (this->_n <= rhs._n);}
    int getName() const {return this->_n;}
    
    private: 
    int _n;
};


std::ostream & operator<<(std::ostream & out, Awesome const& obj)
{
    out << obj.getName() << std::endl;
    return out;
}
int main( void ) {

    Awesome fst(10);
    Awesome snd(20);
    std::cout << max<Awesome>(fst, snd);
// int a = 2;
// int b = 3;
// ::swap( a, b );
// std::cout << "a = " << a << ", b = " << b << std::endl;
// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// std::string c = "chaine1";
// std::string d = "chaine2";
// ::swap(c, d);
// std::cout << "c = " << c << ", d = " << d << std::endl;
// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}