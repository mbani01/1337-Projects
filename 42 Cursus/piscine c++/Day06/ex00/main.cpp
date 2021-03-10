/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:33:37 by mbani             #+#    #+#             */
/*   Updated: 2021/03/02 10:35:10 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void convert_char_int(const char*, char*);
void convert_double_float(const char*);

int main(int argc, char** argv)
{
    (void) argc;
    if (argc != 2)
        exit(1);
    convert_char_int(argv[1], NULL);
    convert_double_float(argv[1]);
    return 0;
}