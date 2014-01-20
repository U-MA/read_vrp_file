#ifndef VRP_H
#define VRP_H

#include <string>

class Vrp
{
public:
    Vrp(const char *filepath);

    std::string name(void) const;
    int         demension() const;
    std::string edge_weight_type(void) const;
    std::string edge_weight_format(void) const;
    std::string display_data_type(void) const;
    int         capacity(void) const;

private:
    std::string name_;
    int         demension_;
    std::string edge_weight_type_;
    std::string edge_weight_format_;
    std::string display_data_type_;
    int         capacity_;
};

#endif /* VRP_H */
