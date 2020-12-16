/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 02:14:56 by mbani             #+#    #+#             */
/*   Updated: 2020/04/03 02:31:52 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
 int main(int argc, char **argv)
 {
     int i=1;
     int j=0;
     if(argc == 1)
        {
            std::cout<<std::endl;
            return 0;
            }
     while(argv[i])
     {
         j = 0;
         while(argv[i][j])
         {
             if(argv[i][j] >= 97 && argv[i][j] <= 122)
             argv[i][j]-=32;
             j++;
         }
         std::cout<<argv[i];
         i++;
     }
 }