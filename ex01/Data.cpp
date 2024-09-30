#include "Data.hpp"

Data::Data()
{
    _data = 1;
}

Data::Data(Data const & src)
{
    *this = src;
}

Data & Data::operator=(Data const & src)
{
    if (this != &src)
        _data = src.getData();
    return *this;
}

void Data::setData(int data)
{
    _data = data;
}

int Data::getData() const
{
    return _data;
}

Data::~Data() {}