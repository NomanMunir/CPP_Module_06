#include "ScalarConverter.hpp"

bool isChar(std::string input)
{
	if (input.length() == 1 && isalpha(input[0]) && std::isprint(input[0]))
		return (true);
	return (false);
}

bool isInt(std::string input)
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

bool isDouble(std::string input)
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

bool isFloat(std::string input)
{
	if (input.find('.') == 0 || input.find('.') == input.length() - 2 || input.find('.') == std::string::npos || input[input.length() - 1] != 'f')
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

void ScalarConverter::setType(std::string input)
{
	_input = input;
	_impossible = false;
	if (isChar(input))
		_type = 0;
	else if (isInt(input))
		_type = 1;
	else if (isDouble(input))
		_type = 2;
	else if (isFloat(input))
		_type = 3;
	else if (!input.compare("+inf") || !input.compare("-inf") ||!input.compare("inf") \
			||!input.compare("inff") ||!input.compare("-inff") ||!input.compare("+inff") \
			|| !input.compare("nan") ||!input.compare("-nan") ||!input.compare("+nan") \
			|| !input.compare("nanf") ||!input.compare("-nanf") ||!input.compare("+nanf"))
			_type = 4;
	else
		_type = 5;
}

void ScalarConverter::isImpossible()
{
	double value;
	try
	{
		value = std::stoi(_input);
		std::cout << "int : " << value << std::endl;
		if (std::isprint(static_cast<char>(value)))
			std::cout << "char : " << static_cast<char>(value) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "int : impossible!" << std::endl;
		std::cout << "char: impossible!" << std::endl;
	}
	try
	{
		value = std::stod(_input);
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

	try
	{
		value = std::stof(_input);
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
void ScalarConverter::convert(std::string input)
{
	ScalarConverter c;
	c.setType(input);
	if(c._type == 5)
	{
		std::cout << "invalid input!" << std::endl;
		return ;
	}
	if (c._type == 0)
	{
		std::cout << "char: " << input << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		return;
	}
	c.isImpossible();
}
