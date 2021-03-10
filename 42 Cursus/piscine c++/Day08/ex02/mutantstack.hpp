/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:07:48 by mbani             #+#    #+#             */
/*   Updated: 2021/03/09 17:38:57 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <algorithm>
#include <stack>


template<typename T>
class MutantStack : public std::stack<T>
{

    public:
        MutantStack();
        MutantStack(const MutantStack<T> &);
        void operator=(const MutantStack<T> &);
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();
        ~MutantStack();
};



#endif