/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:42:42 by mbani             #+#    #+#             */
/*   Updated: 2021/03/09 17:21:46 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        std::vector<int> vect;
        unsigned int max_ele;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &);
        void operator=(const Span &);
        void addNumber(int i);
        void addNumber(std::vector<int>::iterator & begin, std::vector<int>::iterator & end);
        int shortestSpan();
        int longestSpan();
        ~Span();
};

#endif