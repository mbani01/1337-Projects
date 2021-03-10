/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:52:29 by mbani             #+#    #+#             */
/*   Updated: 2021/03/09 17:27:03 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N)
{
    this->vect.reserve(N);
    max_ele = N;
}

Span::Span(const Span &obj)
{
    *this = obj;
}

void Span::operator=(const Span &obj)
{
    this->vect = obj.vect;
    this->max_ele = obj.max_ele;
}

void Span::addNumber(int val)
{
    if (this->vect.size() >= max_ele)
        throw std::exception();
    else
        this->vect.push_back(val);
}

void Span::addNumber(std::vector<int>::iterator & begin, std::vector<int>::iterator & end)
{
    std::vector<int>::iterator it = begin;
    for(it = begin; it != end; it++)
    {
        if (this->vect.size() >= max_ele)
            throw std::exception();
        else
            this->vect.push_back(*it);
    }
}

int Span::shortestSpan()
{
   if ((vect.size() == 1 || vect.empty()))
        throw std::exception();
    std::sort(this->vect.begin(), this->vect.end());
    long long diff;
    for (unsigned int i = 0; i < this->vect.size() - 1; i++)
        if (static_cast<long long>(vect[i + 1]) - static_cast<long long>(vect[i]) < diff)
            diff = (vect[i + 1]) - (vect[i]);
    return static_cast<long long>(diff);
}

int Span::longestSpan()
{
    if ((vect.size() == 1 || vect.empty()))
        throw std::exception();
    return static_cast<int>(static_cast<long long>(*std::max_element(this->vect.begin(), this->vect.end())) -
     static_cast<long long>(*std::min_element(this->vect.begin(), this->vect.end())));
}
Span::~Span()
{
}
