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
}

std::string Vrp::name(void) const
{
    return name_;
}
