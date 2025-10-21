/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:21:20 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/21 13:06:26 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data* data = new Data;
    data->value = 42;
    
    std::cout << "Original pointer: " << data << std::endl;
    std::cout << "Original value: " << data->value << std::endl;
    
    // Serialize: convert pointer to unsigned integer
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized: " << raw << std::endl;
    
    // Deserialize: convert unsigned integer back to pointer
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Deserialized value: " << ptr->value << std::endl;
    
    // Check if they're the same
    std::cout << "Are they equal? " << (data == ptr ? "Yes" : "No") << std::endl;
    
    delete data;
    return 0;
}