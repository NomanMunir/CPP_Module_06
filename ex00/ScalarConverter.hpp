/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:06 by nmunir            #+#    #+#             */
/*   Updated: 2024/04/03 11:08:28 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <limits>

class ScalarConverter
{	private:
		ScalarConverter();
		ScalarConverter(const  ScalarConverter& other);
		ScalarConverter& operator=(const  ScalarConverter& rhs);
		~ScalarConverter();
	public:
		static bool validateInput(std::string input);
		static void convert(std::string input);

		static void printChar(std::string input);
		static void printFloat(std::string input);
		static void printDouble(std::string input);
		static void printInt(std::string input);

		static bool isFloat(std::string input);
		static bool isDouble(std::string input);
		static bool isInt(std::string input);
		static bool isChar(std::string input);

};
#endif // !SCALARCONVERTER_HPP
