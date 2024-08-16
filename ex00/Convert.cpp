#include "Convert.hpp"

ScalarConverter::ScalarConverter() {}

void    to_char(std::string input)
{
    std::cout << "char: " << input[0] << std::endl;
    std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    std::cout << "float: " << std::fixed <<std::setprecision(1)<< static_cast<float>(input[0]) << std::endl;
    std::cout << "double: " << std::fixed <<std::setprecision(1)<< static_cast<double>(input[0]) << std::endl;
}

void    to_int(std::string input)
{
    std::cout << "char: " << input[0] << std::endl;
    std::cout << "int: " << static_cast<int>(std::atoi(input.c_str())) << std::endl;
    std::cout << "float: " << std::fixed <<std::setprecision(1)<< static_cast<float>(input[0]) << std::endl;
    std::cout << "double: " << std::fixed <<std::setprecision(1)<< static_cast<double>(input[0]) << std::endl;
}

void    ScalarConverter::Convert(std::string input)
{
    if(input.length() == 1 && !isdigit(input[0]))
        to_char(input);
    else if(input.length() == 1 && isdigit(input[0]))
        to_int(input);
    // else if(input.length() > 1
}

