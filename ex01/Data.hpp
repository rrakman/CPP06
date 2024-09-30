#pragma once

class Data
{
    private:
        int _data;
    public:
        Data();
        Data(Data const & src);
        Data & operator=(Data const & src);
        ~Data();
        void setData(int data);
        int getData() const;
};