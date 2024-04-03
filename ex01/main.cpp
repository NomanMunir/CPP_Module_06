/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:10 by nmunir            #+#    #+#             */
/*   Updated: 2024/04/03 12:01:01 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main (void)
{
	Data ptr ;
	ptr.a = 12;
	uintptr_t b = 121;
	Data* deserialized = Serializer::deserialize(b);
	uintptr_t serialized = Serializer::serialize(deserialized);
	std::cout << "Original value: " << b << std::endl;
    // std::cout << "Deserialized value: " << deserialized->a << std::endl;
    std::cout << "Serialized value: " << serialized << std::endl;
	return (0);
}
