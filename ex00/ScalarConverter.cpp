/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:01 by nmunir            #+#    #+#             */
/*   Updated: 2024/04/04 12:11:44 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const  ScalarConverter& other) { (void) other; }
ScalarConverter& ScalarConverter::operator=(const  ScalarConverter& rhs) { (void) rhs; return (*this); }
ScalarConverter::~ScalarConverter() {}


static int validate_input(std::string& input)
{
		if (input.find(' ') != std::string::npos) { std::cout << "Space found!" << std::endl;  return (1); }
	return (0);
}

static void printChar(int c)
{
	if (isprint(c))
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	else if (c > 255 || c < 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void printInt(std::string& input)
{
	try
	{
		int i = std::stoi(input);
		if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
			std::cout << "char: impossible" << std::endl;
		else if (isprint(i))
			std::cout << "char: " << static_cast<char>(i) << std::endl;
		else
			std::cout << "char:  Non displayable" << std::endl;
		if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void printFloat(std::string& input)
{
	try
	{
		float f = std::stof(input);
		if (std::isnan(f))
			std::cout << "double: nanf" << std::endl;
		else if (std::isinf(f))
			std::cout << "double: inff" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "float: impossible" << std::endl;
	}
}

void printDouble(std::string& input)
{
	try
	{
		double d = std::stod(input);
		if (std::isnan(d))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(d))
			std::cout << "double: inf" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::convert(std::string input)
{
	if (input.length() == 1 && isprint(input[0]))
	{
		printChar(input[0]);
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
		return ;
	}
	if (validate_input(input))
		return ;
	printInt(input);
	printFloat(input);
	printDouble(input);
}
