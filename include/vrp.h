#ifndef VRP_H
#define VRP_H

#include <string>

class Vrp
{
public:
    Vrp(const char *filepath);

    std::string name(void) const;
    int demension() const;

private:
    std::string name_;
    int         demension_;
};

#endif /* VRP_H */
