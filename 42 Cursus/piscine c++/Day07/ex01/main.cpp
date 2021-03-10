/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:18:19 by mbani             #+#    #+#             */
/*   Updated: 2021/03/05 14:56:35 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void fun(T r)
{
    std::cout<< "the number is " << r << std::endl;
}

int main()
{

    int iarr[3] = {1, 2, 3};
    float farr[5] = {0.9f, 1.1f, 5.5f, 2.9f, 100.100f};
    iter(iarr, 3, fun);
    iter(farr, 5, fun);
}