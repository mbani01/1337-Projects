/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:53:03 by mbani             #+#    #+#             */
/*   Updated: 2021/03/09 17:29:19 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    

    std::cout << std::endl;
    Span sp1 = Span(100);
    Span sp2;
    std::vector<int> vect; 
    
    for(int i = 1; i <= 100; i++)
        vect.push_back(i);
    std::vector<int>::iterator it = vect.begin();
    std::vector<int>::iterator it2 = vect.end();   
    sp1.addNumber(it, it2);
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    sp2 = sp1;
    try
    {
        sp2.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}