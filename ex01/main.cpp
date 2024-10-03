#include "Serialize.hpp"

int main()
{
    Data* data = new Data();

    data->setData(1337);
    
    std::cout<< "Data: " << data->getData() << std::endl;

    uintptr_t p = Serialize::serialize(data);
    // you better not play with bits
    Data * newdata = Serialize::deserialize(p);

    std::cout<< "Data: " << newdata->getData() << std::endl;
    
    newdata->setData(42);
    
    std::cout<< "Data: " << newdata->getData() << std::endl;
    std::cout<< "Data: " << data->getData() << std::endl;
    
    if (data == newdata)
        std::cout << "\033[1;32mdata and newdata have the same address: "<< data <<"\033[0m"<<std::endl;
    return EXIT_SUCCESS;
}