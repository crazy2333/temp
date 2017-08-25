#pragma once




#include <string>






class SHA256
{
public:
    SHA256(const unsigned char * data,size_t size);
    ~SHA256(){};  



    void get_hash(uint32_t * result);



private:
    uint32_t s[8];

    const unsigned char * p_data;
    size_t _size;
    size_t _zeros;
    size_t _blocks;
};

