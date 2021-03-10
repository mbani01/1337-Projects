/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:43:53 by mbani             #+#    #+#             */
/*   Updated: 2021/03/09 17:46:11 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mutantstack.cpp"

int main()
{
    MutantStack<int> mstack; 
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++it;
    --it;
    std::cout << "------------iterator-------------" << std::endl;
    while (it != ite) 
    {
        std::cout << *it << std::endl;
        ++it; 
    }
    std::cout << "---------reverse iterator-----------" << std::endl;
    for (; rit != rite; rit++)
        std::cout << *rit << std::endl;

    std::stack<int> s(mstack); 
    std::cout << "---------char Stack--------------" << std::endl;
    MutantStack<char>   charStack, char2Stack;
    charStack.push('a');
    charStack.push('b');
    charStack.push('c');
    MutantStack<char>::iterator cit = charStack.begin();
    MutantStack<char>::iterator cite = charStack.end();
    for (; cit != cite; cit++)
        std::cout << *cit << std::endl;
    charStack.pop();
    std::cout << "last element poped" << std::endl; 
    
    std::cout << "top : " << charStack.top() << std::endl;
    std::cout << "size : " << charStack.size() << std::endl;
    std::cout << "is empty: " << charStack.empty() << std::endl;
    std::cout << "------- char2Stack -------"  << std::endl;
    char2Stack = charStack;
    MutantStack<char>::iterator cit2 = char2Stack.begin();
    MutantStack<char>::iterator cite2 = char2Stack.end();
    for (; cit2 != cite2; cit2++)
        std::cout << *cit2 << std::endl;
    std::cout << "--------- copy Stack-------" << std::endl;
    MutantStack<char> copyStack(charStack);
    MutantStack<char>::iterator citc = copyStack.begin();
    MutantStack<char>::iterator citec = copyStack.end();
    for (; citc != citec; citc++)
        std::cout << *citc << std::endl;
    return 0;
}