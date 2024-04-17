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

void  ScalarConverter::printInt(std::string input, int flag)
{
	double value;

	value = atoll(input.c_str());
	int maxInt = std::numeric_limits<int>::max();
	
	if (value > maxInt || value < -maxInt - 1 || flag == 2 || flag == 3)
	{
		std::cout << "char: impossible!" << std::endl;
		std::cerr << "int : impossible!" << std::endl;
		return ;
	}
	std::cout << "int : " << static_cast<int>(value) << std::endl;
	if (value > 31 && value < 127)
		std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void  ScalarConverter::printDouble(std::string input, int flag)
{
	std::cout << "double : ";
	if (input[0] == '+')
		input = input.erase(0,1);
	if (flag == 2)
	{
		std::cout << input << std::endl;
		return ;
	}
	else if (flag == 3)
	{
		std::cout << input.substr(0, input.size() - 1) << std::endl;
		return ;
	}
	double value = atof(input.c_str());
	double maxDouble = std::numeric_limits<double>::max();
	if ( value > maxDouble || value < -maxDouble)
	{
		std::cerr << "impossible!" << std::endl;
		return ;
	}
	else
	{
		std::cout << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
	}
	std::cout << std::endl;
}

void  ScalarConverter::printFloat(std::string input, int flag)
{
	std::cout << "float : ";
	if (input[0] == '+')
		input = input.erase(0,1);
	if (flag == 3)
	{
		std::cout << input << std::endl;
		return ;
	}
	else if (flag == 2)
	{
		std::cout << input << "f" <<std::endl;
		return ;
	}
	double maxFloat = std::numeric_limits<float>::max();
	double value = atof(input.c_str());
	if (value > maxFloat || value < -maxFloat)
	{
		std::cerr << "impossible!" << std::endl;
		return ;
	}
	else
	{
		std::cout << static_cast<float>(value);
		if (value == static_cast<int>(value))
			std::cout << ".0";
	}
	std::cout << "f" << std::endl;

}

void  ScalarConverter::printChar(std::string input)
{
	std::cout << "char: '" << input << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
}

int ScalarConverter::validateInput(std::string input)
{
	if (isChar(input) || isInt(input) || isDouble(input) ||	isFloat(input))
		return (0);
	else if (	!input.compare("+inf") || !input.compare("-inf")  || !input.compare("inf") \
			|| 	!input.compare("nan")  || !input.compare("-nan")  || !input.compare("+nan"))
		return (2);
	else if (	!input.compare("inff") || !input.compare("-inff") || !input.compare("+inff") \
			|| 	!input.compare("nanf") || !input.compare("-nanf") || !input.compare("+nanf"))
		return (3);
	else
	{
		std::cout << "Invalid input!" << std::endl;
		return (1);
	}
}

void ScalarConverter::convert(std::string input)
{
	int flag = ScalarConverter::validateInput(input);
	if(flag == 1)
		return ;
	if (isChar(input))
		return (printChar(input));
	printInt(input, flag);
	printDouble(input, flag);
	printFloat(input, flag);
}
