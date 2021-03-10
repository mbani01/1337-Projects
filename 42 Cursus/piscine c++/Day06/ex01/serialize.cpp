/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:52:13 by mbani             #+#    #+#             */
/*   Updated: 2021/03/02 16:22:57 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

void * serialize(void)
{
    char *data = new char[21];
    static int i;
	char		letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l',
	'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	srand(time(0));
	for(int j = 0; j < 8; j++)
	{	
		i += rand() % 26;
        if (j % 2)
            data[j] = letters[i % 26];
        else
            data[j] = numbers[i % 10];
	}
    for(int k = 8; k < 12; k++)
    {
        i += rand() % 10;
        data[k] = numbers[i % 10];
    }
 	for(int x = 12; x < 20; x++)
	{	
		i += rand() % 26;
        if (x % 2)
            data[x] = letters[i % 26];
        else
            data[x] = numbers[i % 10];
	}
    data[20] = '\0';
    return data;
}



Data *deserialize(void *raw)
{
    Data *ptr = new Data;

    char *tmp = strdup(reinterpret_cast<char*>(raw));
    tmp[8] = '\0';
    ptr->s1 = reinterpret_cast<char *>(tmp);
    char *tmp2= NULL;
    char *tmp1 = tmp2 = strdup(reinterpret_cast<char*>(raw));
    tmp1 += 8;
    tmp1[12] = '\0';
    ptr->n = reinterpret_cast<intptr_t>(tmp1);
    ptr->s2 = reinterpret_cast<char *>(tmp + 12);
    delete tmp2;
    delete tmp;

    return ptr;
}
