#ifndef VRP_H
#define VRP_H

#include <string>

class Vrp
{
public:
    Vrp(const char *filepath);

    std::string name(void) const;

private:
    std::string name_;
};

#endif /* VRP_H */
