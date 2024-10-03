#include"A.hpp"
#include"B.hpp"
#include"C.hpp"
#include"Base.hpp"

Base * generate(void)
{
    std::ifstream file("/dev/urandom");
    unsigned int seed;
    file.read(reinterpret_cast<char*>(&seed), sizeof(seed));
    file.close();
    srand(seed);
    int random_number = rand() / ((RAND_MAX + 1u) / 3);

    if (random_number == 0)
    {
        return new A;
    }
    else if (random_number == 1)
    {
        return new B;
    }
    else
    {
        return new C;
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        A& __unused a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;

    }
    catch(const std::bad_cast& e)
    {
        try
        {
            B& __unused b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch(const std::bad_cast& e)
        {
            try
            {
                C& __unused c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch(const std::bad_cast& e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main()
{
    Base *basep = generate();
    Base &baser = *basep;
    identify(baser);
    identify(basep);
    return 0;
}