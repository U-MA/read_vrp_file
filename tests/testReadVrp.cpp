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
}

TEST(ReadVrpFile, demension)
{
    Vrp vrp("Vrp-All/E/E-n13-k4.vrp");

    LONGS_EQUAL(13, vrp.demension());
}

TEST(ReadVrpFile, edge_weight_type)
{
    Vrp vrp("Vrp-All/E/E-n13-k4.vrp");
    CHECK_EQUAL("EXPLICIT", vrp.edge_weight_type());
}
