#ifndef VRP_H
#define VRP_H

#include <string>

class Vrp
{
public:
    Vrp(const char *filepath);

    std::string name(void) const;
    int demension() const;
    std::string edge_weight_type(void) const;
    std::string edge_weight_format(void) const;

private:
    std::string name_;
    int         demension_;
    std::string edge_weight_type_;
    std::string edge_weight_format_;
};

#endif /* VRP_H */
