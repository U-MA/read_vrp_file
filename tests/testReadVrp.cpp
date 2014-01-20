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

TEST(ReadVrpFile, edge_weight_format)
{
    CHECK_EQUAL("LOWER_ROW", vrp->edge_weight_format());
}

TEST(ReadVrpFile, display_data_type)
{
    CHECK_EQUAL("NO_DISPLAY", vrp->display_data_type());
}

TEST(ReadVrpFile, capacity)
{
    LONGS_EQUAL(6000, vrp->capacity());
}
