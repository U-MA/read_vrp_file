#include "CppUTest/TestHarness.h"

#include <iostream>
#include <string>
#include <sstream>

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

TEST(ReadVrpFile, cost)
{
    LONGS_EQUAL(9 , vrp->cost(1, 0));
    LONGS_EQUAL(14, vrp->cost(2, 0));
    LONGS_EQUAL(42, vrp->cost(4, 3));
    LONGS_EQUAL(10, vrp->cost(12, 11));
}

TEST(ReadVrpFile, experiment1)
{
    std::string str("    12    23    34");
    int expect[3] = { 12, 23, 34 };

    std::istringstream iss(str);
    int num;
    iss >> num;
    LONGS_EQUAL(expect[0], num);
    iss >> num;
    LONGS_EQUAL(expect[1], num);
    iss >> num;
    LONGS_EQUAL(expect[2], num);
}
