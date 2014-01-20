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

    std::getline(ifs, str); // edge_weight_type
    edge_weight_type_ = str.substr(19);

    std::getline(ifs, str); // edge_weight_format
    edge_weight_format_ = str.substr(20);

    std::getline(ifs, str); // display_data_type
    display_data_type_ = str.substr(19);
}

std::string Vrp::name(void) const
{
    return name_;
}

int Vrp::demension(void) const
{
    return demension_;
}

std::string Vrp::edge_weight_type(void) const
{
    return edge_weight_type_;
}

std::string Vrp::edge_weight_format(void) const
{
    return edge_weight_format_;
}

std::string Vrp::display_data_type(void) const
{
    return display_data_type_;
}
