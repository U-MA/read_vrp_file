#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "vrp.h"

static bool findKeyword(const std::string &str, const char *keyword)
{
    return (str.find(keyword, 0) != std::string::npos);
}

Vrp::Vrp(const char *filepath)
{
    std::ifstream ifs(filepath);
    if (ifs.fail())
    {
        std::cout << "Can't open file" << std::endl;
        exit(1);
    }

    std::string str;
    while (std::getline(ifs, str))
    {
        if (findKeyword(str, "NAME"))
            name_ = str.substr(7);
        else if (findKeyword(str, "DIMENSION"))
            std::sscanf(str.data()+12, "%d", &demension_);
        else if (findKeyword(str, "EDGE_WEIGHT_TYPE"))
            edge_weight_type_ = str.substr(19);
        else if (findKeyword(str, "EDGE_WEIGHT_FORMAT"))
            edge_weight_format_ = str.substr(20);
        else if (findKeyword(str, "DISPLAY_DATA_TYPE"))
            display_data_type_ = str.substr(19);
        else if (findKeyword(str, "CAPACITY"))
            std::sscanf(str.data()+11, "%d", &capacity_);
        else if (findKeyword(str, "EDGE_WEIGHT_SECTION"))
        {
            size_t edge_size = demension_ * (demension_-1) / 2;
            cost_ = new int[edge_size];

            size_t i=0;
            while (i < edge_size)
            {
                std::getline(ifs, str);
                std::istringstream iss(str);
                while (iss.tellg() != (int)str.length())
                    iss >> cost_[i++];
            }
        }
    }
}

Vrp::~Vrp(void)
{
    delete[] cost_;
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

int Vrp::capacity(void) const
{
    return capacity_;
}

int Vrp::cost(int v0, int v1) const
{
    const int cost_index = (v1 > v0) ? v1*(v1-1)/2+v0 :
                                       v0*(v0-1)/2+v1;
    return cost_[cost_index];
}
