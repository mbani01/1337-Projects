/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutanstack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:40:24 by mbani             #+#    #+#             */
/*   Updated: 2021/03/09 17:46:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"


template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}
template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &obj)
{
    *this = obj;
}

template<typename T>
void MutantStack<T>::operator=(const MutantStack &obj)
{
    this->c = obj.c;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}
