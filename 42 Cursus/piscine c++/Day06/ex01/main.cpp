/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:22:52 by mbani             #+#    #+#             */
/*   Updated: 2021/03/02 16:23:04 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "serialize.hpp"

int main()
{
    void * rand = serialize();
    Data * dt = deserialize(rand);
    std::cout << reinterpret_cast<char *>(rand) << std::endl;
    std::cout << dt->s1 << std::endl;
    std::cout << dt->n << std::endl;
    std::cout << dt->s2 << std::endl;
    delete dt;
}