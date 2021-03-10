/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:26:15 by mbani             #+#    #+#             */
/*   Updated: 2021/03/02 17:58:48 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
    Base *b[3] = {new A(),new B(),new C()};
    static int i;
    srand(time(NULL));
    i += rand() % 3;
    for(int j = 0; j < 3; j++)
    {
        if (j!=i)
            delete b[j];
    }
    return b[i];
}

void identify_from_pointer(Base *p)
{
   A *A_obj = dynamic_cast<A*>(p);
   B *B_obj = dynamic_cast<B*>(p);
   C *C_obj = dynamic_cast<C*>(p);
    if (A_obj)
        std::cout << "A" << std::endl;
    if (B_obj)
        std::cout << "B" << std::endl;
    if (C_obj)
        std::cout << "C" << std::endl;
}
void identify_from_reference(Base & p)
{
    try
    {
        A & A_obj = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)A_obj;
    }
    catch(const std::exception& e)
    {
    }

    try
    {
        B & B_obj = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)B_obj;
    }
    catch(const std::exception& e)
    {
    }

    try
    {
        C & C_obj = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)C_obj;
    }
    catch(const std::exception& e)
    {
    }
}

int main()
{
    Base *b = nullptr;
    b = generate();
    identify_from_pointer(b);
    identify_from_reference(*b);
}