#include"Convert.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        std::string litteral(av[1]);
        ScalarConverter::Convert(litteral);
    }
    else
        std::cout << "Usgae: ./Convert \"any litteral\"" << std::endl;
    return 0;
}