/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:54:08 by mbani             #+#    #+#             */
/*   Updated: 2021/03/05 11:41:04 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
int main(void)
{
    Array<int> arr(6);
    Array<int> arr1(5);
    Array<char> char_arr(20);
    try
    {
        arr[0] = 4;
        std::cout << arr[0] << std::endl;
        arr = arr1;
        arr1[0] = 5;
        arr[0] = 6;
        char_arr[0] = 'a';
        char_arr[1] = 'b';
        std::cout << arr[0] << " "<< arr1[0] << std::endl;
        for (size_t i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        for (size_t i = 0; i < arr1.size(); ++i)
            std::cout << arr1[i] << " ";
        std::cout << std::endl;
        for (size_t i = 0; i < char_arr.size(); ++i)
            std::cout << char_arr[i] << " ";
        std::cout << std::endl;
        arr1[5] = 10;
        std::cout << arr[2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}