/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:22:51 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/14 15:13:26 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>

ScalarConverter::ScalarConverter(const std::string& str): str(str){
}
ScalarConverter::~ScalarConverter(){
}
ScalarConverter::ScalarConverter(const ScalarConverter& copy): str(copy.str){
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy){
    if(this != &copy){
        str = copy.str;
    }
    return *this;
}
void ScalarConverter::convert(const std::string& str){

    printChar(str);
    printInt(str);
    printFloat(str);
    printDouble(str);
}
void ScalarConverter::printChar(const std::string& str){
    // Check for special values
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || 
        str == "+inff" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    
    // Special case: single character input (like 'a')
    if (str.length() == 1 && !isdigit(str[0])) {
        char c = str[0];
        if (c < 32 || c > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << c << "'" << std::endl;
        }
        return;
    }
    
    // Try to convert to double (for numeric inputs like "42", "42.5f", etc.)
    char* end;
    double d = std::strtod(str.c_str(), &end);
    
    // Check if conversion failed or out of char range
    if (*end != '\0' && *end != 'f') {
        std::cout << "char: impossible" << std::endl;
    }
    else if (d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (d < 32 || d > 126) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(const std::string& str){
    // Check for special values
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || 
        str == "+inff" || str == "-inff") {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    // Special case: single character input (like 'a')
    if (str.length() == 1 && !isdigit(str[0])) {
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        return;
    }
    
    // Try to convert to double first (for numeric inputs)
    char* end;
    double d = std::strtod(str.c_str(), &end);
    
    // Check if conversion failed
    if (*end != '\0' && *end != 'f') {
        std::cout << "int: impossible" << std::endl;
    }
    else if (d < INT_MIN || d > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
    }
    else {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
}

void ScalarConverter::printFloat(const std::string& str){
    // Special case: single character input (like 'a')
    if (str.length() == 1 && !isdigit(str[0])) {
        float f = static_cast<float>(str[0]);
        std::cout << "float: " << f << ".0f" << std::endl;
        return;
    }
    
    char* end;
    float f = std::strtof(str.c_str(), &end);
    
    // Check if it's a whole number
    if (f == static_cast<int>(f) && f >= -1000000 && f <= 1000000) {
        std::cout << "float: " << f << ".0f" << std::endl;
    }
    else {
        std::cout << "float: " << f << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(const std::string& str){
    // Special case: single character input (like 'a')
    if (str.length() == 1 && !isdigit(str[0])) {
        double d = static_cast<double>(str[0]);
        std::cout << "double: " << d << ".0" << std::endl;
        return;
    }
    
    char* end;
    double d = std::strtod(str.c_str(), &end);
    
    // Check if it's a whole number
    if (d == static_cast<int>(d) && d >= -1000000 && d <= 1000000) {
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else {
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::printInvalid(){
    std::cout << "Invalid input" << std::endl;
}

void ScalarConverter::printNonDisplayable(){
    std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printNonPrintable(){ 
    std::cout << "Non printable" << std::endl;
}