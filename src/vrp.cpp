#include <fstream>
#include <iostream>
#include <string>

#include "vrp.h"


Vrp::Vrp(const char *filepath)
{
    std::ifstream ifs(filepath);
    if (ifs.fail())
    {
        std::cout << "Can't open file" << std::endl;
        exit(1);
    }

    std::string str;
    std::getline(ifs, str);
    name_ = str.substr(7);

    std::getline(ifs, str); // comment
    std::getline(ifs, str); // type
    std::getline(ifs, str); // demension

    std::sscanf(str.data()+12, "%d", &demension_);
}

std::string Vrp::name(void) const
{
    return name_;
}

int Vrp::demension(void) const
{
    return demension_;
}
