#include"A.hpp"
#include"B.hpp"
#include"C.hpp"
#include <ctime>
#include <cstdlib>

Base * generate(void)
{
    srand(std::time(0));
    int random = rand() % 3;
    std::cout<<"random = "<<random<<std::endl;
    if (random == 0)
    {
        return new A;
    }
    else if (random == 1)
    {
        return new B;
    }
    else
    {
        return new C;
    }
}


int main()
{
    Base *basep = generate();
    
    return 0;
}