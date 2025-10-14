/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:15:26 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/14 14:38:24 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
    private:
        std::string str;
    public:
        ScalarConverter(const std::string& str);
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);

        // Converter
        static void convert(const std::string& str);
        // Print functions
        static void printChar(const std::string& str);
        static void printInt(const std::string& str);
        static void printFloat(const std::string& str);
        static void printDouble(const std::string& str);
        static void printInvalid();
        static void printNonDisplayable();
        static void printNonPrintable();
};

#endif