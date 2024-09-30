#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &ref);
        ScalarConverter& operator=(const ScalarConverter &ref);
        static  void    Convert(std::string input);
};