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
	else
		_type = 4;
	std::cout << _type <<std::endl;
}

void ScalarConverter::isImpossible()
{
	try
	{
		if (_type == 1)
			std::stoi(_input);
		else if (_type == 2)
			std::stod(_input);
		else if (_type == 3)
			std::stof(_input);
	}
	catch(const std::exception& e)
	{
		_impossible = true;
		std::cerr << e.what() << '\n';
	}
}
void ScalarConverter::convert(std::string input)
{
	ScalarConverter c;
	c.setType(input);
	c.isImpossible();
	std::cout << c._impossible;
}
