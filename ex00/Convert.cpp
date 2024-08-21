#include "Convert.hpp"

ScalarConverter::ScalarConverter() {}

void    to_char(std::string input)
{
    std::cout << "char: " << input[0] << std::endl;
    std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    std::cout << "float: " << std::fixed <<std::setprecision(1)<< static_cast<float>(input[0]) << std::endl;
    std::cout << "double: " << std::fixed <<std::setprecision(1)<< static_cast<double>(input[0]) << std::endl;
}

void    to_single_int(std::string input)
{
    std::cout << "char: Non displayable"<< std::endl;
    std::cout << "int: " << static_cast<int>(std::atoi(input.c_str())) << std::endl;
    std::cout << "float: " << std::fixed <<std::setprecision(1)<< static_cast<float>(std::atoi(input.c_str())) << std::endl;
    std::cout << "double: " << std::fixed <<std::setprecision(1)<< static_cast<double>(std::atoi(input.c_str())) << std::endl;
}

void    to_number(std::string input)
{
    int input_num = std::atoi(input.c_str());
    
    if(isprint(input_num))
        std::cout << "char: '" << static_cast<char>(input_num) <<"'" <<std::endl;
    else if (input_num > 128)
        std::cout << "char: Impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(std::atoi(input.c_str())) << std::endl;
    (input);
    std::cout << "float: " << std::fixed <<std::setprecision(2)<< static_cast<float>(std::strtod(input.c_str(),NULL)) << "f"<<std::endl;
    std::cout << "double: " << std::fixed <<std::setprecision(2)<< static_cast<double>(std::strtod(input.c_str(),NULL)) << std::endl;
}

bool    isValidnumber(std::string input)
{
    std::size_t pos = input.find(".");
    if(pos == std::string::npos)
    {   
        std::size_t i;
        if(input[0] == '-' || input[0] == '+')
            i = 1;
        else
            i = 0;
        for(; i < input.length(); i++)
        {
            if(!isdigit(input[i]))
                return false;
        }
    }
    else
    {
        std::size_t i;
        if(input[0] == '-' || input[0] == '+')
            i = 1;
        else
            i = 0;
        for(; i < pos; i++)
        {
            if(!isdigit(input[i]))
                return false;
        }
        for(std::size_t i = pos + 1; i < input.length(); i++)
        {
            if(input[i] == 'f' && input[i + 1] == '\0')
                return true;
            if(!isdigit(input[i]))
                return false;
        }
    }
    return true;
}

void    ScalarConverter::Convert(std::string input)
{
    if(input.length() == 1 && !isdigit(input[0]))
        to_char(input);
    else if(input.length() == 1 && isdigit(input[0]))
        to_single_int(input);
    else if(input.length() > 1 && isValidnumber(input))
        to_number(input);
    else
        std::cout<<"invalid\n";
}

