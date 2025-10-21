/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:42:21 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/21 14:22:27 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

A::A()  
{
}
A::~A()
{
}
B::B()
{
}
B::~B()
{
}
C::C()
{
}
C::~C()
{
}
void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
    {
        std::cout << "\033[31m" << "Object pointed by p actually is A" << "\033[0m" << std::endl;
    }
    else if(dynamic_cast<B*>(p))
    {
        std::cout << "\033[32m" << "Object pointed by p actually is B" << "\033[0m" << std::endl;
    }
    else if(dynamic_cast<C*>(p))
    {
        std::cout << "\033[33m" << "Object pointed by p actually is C" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[30m" << "Object pointed by p is not a Base" << "\033[0m" << std::endl;
    }
}

void identify(Base& p)
{
    try{
        A& a = dynamic_cast<A&>(p);
        (void)a; // suppress the warning
        std::cout << "\033[31m" << "Identified object as A" << "\033[0m" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
    }
    try{
        B& b = dynamic_cast<B&>(p);
        (void)b; // suppress the warning
        std::cout << "\033[32m" << "Identified object as B" << "\033[0m" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
    }
    try{
        C& c = dynamic_cast<C&>(p);
        (void)c; // suppress the warning
        std::cout << "\033[33m" << "Identified object as C" << "\033[0m" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cout << "\033[30m" << "Object pointed by p is not a Base" << "\033[0m" << std::endl;
    }
}