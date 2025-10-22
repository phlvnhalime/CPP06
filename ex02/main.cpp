/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:09:37 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/21 14:17:23 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "identify.hpp"

int main(int ac, char **av)
{
    if(ac != 1 || av[1])
    {
        std::cout << "Usage: ./identify" << std::endl;
        return 1;
    }
    srand(time(NULL));
    Base* base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}