#include "CppUTest/TestHarness.h"

#include <string>

#include "vrp.h"

TEST_GROUP(ReadVrpFile)
{
};

TEST(ReadVrpFile, name)
{
    Vrp vrp("Vrp-All/E/E-n13-k4.vrp");

    std::string name = vrp.name();

    CHECK_EQUAL("E-n13-k4", name);

    Vrp vrp2("Vrp-All/E/E-n101-k14.vrp");

    name = vrp2.name();

    CHECK_EQUAL("E-n101-k14", name);
}
