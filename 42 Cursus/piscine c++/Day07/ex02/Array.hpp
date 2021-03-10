/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:03:33 by mbani             #+#    #+#             */
/*   Updated: 2021/03/05 11:47:01 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template<typename T>
class Array
{
    private:
        T *_ptr;
        size_t _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T> &);
        void operator=(const Array<T> &);
        T & operator[](size_t );
        size_t size() const;
        ~Array();
};

template<typename T>
Array<T>::Array():_ptr(nullptr)
{
}
template<typename T>
Array<T>::Array(unsigned int n)
{
    this->_ptr = new(std::nothrow) T[n]();
    _size = n;
    if (!_ptr)
        std::cout << "Allocation Failed !!"<< std::endl;
}

template<typename T>
Array<T>::~Array()
{
}

template<typename T>
Array<T>::Array(const Array<T> &obj)
{
    *this = obj;
}

template<typename T>
void Array<T>::operator=(const Array<T> &obj)
{
    if (this->_ptr)
        delete [] _ptr;
    this->_ptr = new T[obj._size]();
    this->_size = obj._size;
    for(size_t i = 0; i < obj.size(); i++)
    {
        this->_ptr[i] = obj._ptr[i];   
    }
}

template<typename T>
T& Array<T>::operator[](size_t n)
{
    if (n < _size)
        return _ptr[n];
    else
        throw std::exception();
}

template<typename T>
size_t Array<T>::size() const
{
    return _size;
}

#endif