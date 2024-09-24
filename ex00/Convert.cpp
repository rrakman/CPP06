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

int get_afterdot_size(std::string input)
{
    std::size_t pos = input.find(".");
    if(pos == std::string::npos)
        return 1;
    return input.length() - pos - 1;
}

void    to_number(std::string input)
{
    long input_num = std::atol(input.c_str());
    int size = get_afterdot_size(input);
    
    if(isprint(input_num))
        std::cout << "char: '" << static_cast<char>(input_num) <<"'" <<std::endl;
    else if (input_num > 128)
        std::cout << "char: Impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    if (input_num > std::numeric_limits<int>::max() || input_num < std::numeric_limits<int>::min())
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int> (std::atoi(input.c_str())) << std::endl;

    if (std::strtof(input.c_str(),NULL) > std::numeric_limits<float>::max() || std::strtof(input.c_str(),NULL) < std::numeric_limits<float>::min())
    {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inff" << std::endl;
    }
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(size) << static_cast<float>(std::strtof(input.c_str(),NULL)) << "f"<<std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(size) << static_cast<double>(std::strtod(input.c_str(),NULL)) << std::endl;
    }
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

void    print_invalid()
{
    std::cout<<"char: impossible\n";
    std::cout<<"int: impossible\n";
    std::cout<<"float: nanf\n";
    std::cout<<"double: nan\n";
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
        print_invalid();
}

