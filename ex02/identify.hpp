/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:09:44 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/21 14:06:25 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include <exception>
#include <iostream>

class A : public Base {
    public:
        A();
        ~A();
};

class B : public Base {
    public:
        B();
        ~B();
};

class C : public Base {
    public:
        C();
        ~C();
};

void identify(Base* p); // identify the type of the object
void identify(Base& p); // identify to which class the object belongs

#endif