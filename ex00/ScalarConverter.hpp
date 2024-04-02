#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <limits>
class ScalarConverter
{
	private:
		std::string _input;
	public:
		int _type;
		bool _impossible;
		void isImpossible();
		void setType(std::string input);
		static void convert(std::string input);
};
#endif // !SCALARCONVERTER_HPP



// void convertChar(double value)
// {
// 	if (floor(value) != value || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
// 		std::cout << "char : impossible!" << std::endl;
// 	else if (value > 31 && value < 127)
// 		std::cout << "char : " << static_cast<char> (value) << std::endl;
// 	else
// 		std::cout << "char : non displayable!" << std::endl;
// }

// void convertInt(double value)
// {
// 	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
// 		std::cout << "int : impossible!" << std::endl;
// 	else
// 		std::cout << "int : " << static_cast<int> (value) << std::endl;
// }

// void convertDouble(double value)
// {
// 	std::cout << "double : " << value << std::endl;
// }

// void convertFloat(double value)
// {

// 	std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
// }

// void ScalarConverter::convert(std::string input)
// {

// 	if (input.length() == 1 && !isdigit(input[0]))
// 	{
// 		char c = input[0];
// 		double value = static_cast <double> (c);
// 		convertChar(value);
// 		convertInt(value);
// 		convertFloat(value);
// 		convertDouble(value);
// 	}
// 	else
// 	{
// 		try
// 		{
// 			double value;
// 			value  = std::stod(input);
// 			convertChar(value);
// 			convertInt(value);
// 			convertFloat(value);
// 			convertDouble(value);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	}
// }