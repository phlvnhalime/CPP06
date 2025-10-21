/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:39:27 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/21 14:24:47 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "identify.hpp"


Base::~Base()
{
}

Base* generate(void)
{
    srand(time(NULL));
    int choose = rand() % 3;

    switch (choose) {
        case 0:
            std::cout<< "\033[31m" << "A returns the instance as a Base pointer" << "\033[0m" << std::endl;
            return new A();
        case 1:
            std::cout<< "\033[32m" << "B returns the instance as a Base pointer" << "\033[0m" << std::endl;
            return new B();
        case 2:
            std::cout<< "\033[33m" << "C returns the instance as a Base pointer" << "\033[0m" << std::endl;
            return new C();
    }
    return new Base();
}