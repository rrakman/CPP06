#pragma once
#include "Data.hpp"
#include <cstdint>
#include <stdlib.h>
#include <iostream>

class Serialize
{
    private:
        Serialize();
        Serialize(Serialize const & src);
        Serialize & operator=(Serialize const & src);
        ~Serialize();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};