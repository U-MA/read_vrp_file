#include "CppUTest/TestHarness.h"

#include <string>

#include "vrp.h"

TEST_GROUP(ReadVrpFile)
{
    Vrp *vrp;

    void setup(void)
    {
        vrp = new Vrp("Vrp-All/E/E-n13-k4.vrp");
    }

    void teardown(void)
    {
        delete vrp;
    }
};

TEST(ReadVrpFile, name)
{
    CHECK_EQUAL("E-n13-k4", vrp->name());
}

TEST(ReadVrpFile, demension)
{
    LONGS_EQUAL(13, vrp->demension());
}

TEST(ReadVrpFile, edge_weight_type)
{
    CHECK_EQUAL("EXPLICIT", vrp->edge_weight_type());
}
