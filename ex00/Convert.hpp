#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        static  void    Convert(std::string input);
};