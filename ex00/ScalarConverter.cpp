/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:01 by nmunir            #+#    #+#             */
/*   Updated: 2024/04/03 11:02:57 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const  ScalarConverter& other) { (void) other; }
ScalarConverter& ScalarConverter::operator=(const  ScalarConverter& rhs) { (void) rhs; return (*this); }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(std::string input)
{
	if (input.length() == 1 && isalpha(input[0]) && std::isprint(input[0]))
		return (true);
	return (false);
}

bool ScalarConverter::isInt(std::string input)
{
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isDouble(std::string input)
{
	if (input.find('.') == 0 || input.find('.') == input.length() - 1 || input.find('.') == std::string::npos)
		return (false);
	size_t i = 0;
	size_t count = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; i < input.length(); i++)
	{
		if (input[i] == '.')
			count++;
		if ((!isdigit(input[i]) && input[i] != '.') || count > 1)
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFloat(std::string input)
{
	if (input.find('.') == 0 || input.find('.') == input.length() - 2 \
		|| input.find('.') == std::string::npos \
		|| input[input.length() - 1] != 'f')
		return (false);
	size_t i = 0;
	size_t count = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; i < input.length() - 1; i++)
	{
		if (input[i] == '.')
			count++;
		if ((!isdigit(input[i]) && input[i] != '.') || count > 1)
			return (false);
	}
	return (true);
}

void  ScalarConverter::printInt(std::string input)
{
	int value;
	try
	{
		value = std::stoi(input);
		std::cout << "int : " << value << std::endl;
		if (std::isprint(value))
			std::cout << "char : " << static_cast<char>(value) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "int : impossible!" << std::endl;
		std::cout << "char: impossible!" << std::endl;
	}
}

void  ScalarConverter::printDouble(std::string input)
{
	double value;
	try
	{
		value = std::stod(input);
		std::cout << "double : ";
		if (std::isinf(value))
		{
			if (value < 0)
				std::cout << "-inf";
			else
				std::cout << "+inf";
		}
		else if (std::isnan(value))
			std::cout << "nan";
		else
		{
			std::cout << value;
			if (value == static_cast<int>(value))
				std::cout << ".0";
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "double : impossible!" << std::endl;
	}
}

void  ScalarConverter::printFloat(std::string input)
{
	float value;
	try
	{
		value = std::stof(input);
		std::cout << "float : ";
		if (std::isinf(value))
		{
			if (value < 0)
				std::cout << "-inf";
			else
				std::cout << "+inf";
		}
		else if (std::isnan(value))
			std::cout << "nan";
		else
		{
			std::cout << value;
			if (value == static_cast<int>(value))
				std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "float : impossible!" << std::endl;
	}
}

void  ScalarConverter::printChar(std::string input)
{
	std::cout << "char: " << input << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
}

bool ScalarConverter::validateInput(std::string input)
{
	if (isChar(input) || isInt(input) || isDouble(input) ||	isFloat(input))
		return (false);
	else if (	!input.compare("+inf") || !input.compare("-inf")  || !input.compare("inf") \
			||	!input.compare("inff") || !input.compare("-inff") || !input.compare("+inff") \
			|| 	!input.compare("nan")  || !input.compare("-nan")  || !input.compare("+nan") \
			|| 	!input.compare("nanf") || !input.compare("-nanf") || !input.compare("+nanf"))
		return (false);
	else
	{
		std::cout << "Invalid input!" << std::endl;
		return (true);
	}
}

void ScalarConverter::convert(std::string input)
{
	if(ScalarConverter::validateInput(input))
		return ;
	if (isChar(input))
		return (printChar(input));
	printInt(input);
	printDouble(input);
	printFloat(input);
}
