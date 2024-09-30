#include "Serialize.hpp"

Serialize::Serialize() {}
Serialize::~Serialize() {}
Serialize::Serialize(Serialize const & __unused src) {}
Serialize & Serialize::operator=(Serialize const & __unused src) { return *this; }

uintptr_t Serialize::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
