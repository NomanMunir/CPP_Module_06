/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:10 by nmunir            #+#    #+#             */
/*   Updated: 2024/04/04 12:28:54 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main (void)
{
	Data ptr ;
	ptr.a = 12;
	uintptr_t serialized = Serializer::serialize(&ptr);
	Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Orignal value: " << ptr.a << std::endl;
    std::cout << "Deserialized value: " << deserialized->a << std::endl;
	return (0);
}
