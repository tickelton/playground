#include "gtest/gtest.h"
#include "connect.h"

TEST(connectTest, basicTest) {

    EXPECT_EQ(connect(3), 0);
    //EXPECT_EQ(connect(1), 0);
    EXPECT_EQ(connect(2), 1);
}
