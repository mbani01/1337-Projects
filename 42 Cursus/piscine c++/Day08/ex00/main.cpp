/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:26:31 by mbani             #+#    #+#             */
/*   Updated: 2021/03/06 10:40:37 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> vect;

    for (int x = 0; x < 10; x++)
        vect.push_back(x);
    try
    {
        int occ = easyfind(vect, 9);
        std::cout << occ << std::endl;
        occ = easyfind(vect, 1);
        std::cout << occ << std::endl;
        occ = easyfind(vect, 90);
        std::cout << occ << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}