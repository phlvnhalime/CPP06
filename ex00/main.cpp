/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:33:48 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/14 14:39:44 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv){
    if(argc != 2){
        std::cout << "Usage: ./scalar <value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}