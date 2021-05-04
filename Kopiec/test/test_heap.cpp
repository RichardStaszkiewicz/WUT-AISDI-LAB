#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "heap.hpp"


TEST(test_construct, default_init)
{
    heappy <int, int> x;
    x.insert(-12, 4);
    x.insert(-2, 7);
    x.insert(4, 19);
    EXPECT_EQ(x.pop().first, -12);
    EXPECT_EQ(x.pop().second, 7);
    EXPECT_EQ(x.pop().first, 4);
}

TEST(test_construct, custom_init)
{
    heappy <int, char, 3> x;
    x.insert(-12, 'a');
    x.insert(-2, 'c');
    x.insert(4, 'b');
    EXPECT_EQ(x.pop().second, 'a');
    EXPECT_EQ(x.pop().second, 'c');
    EXPECT_EQ(x.pop().second, 'b');
}

TEST(test_construct, custom_init2)
{
    heappy <int, double, 20> x;
    for(int i = 100; i >= -10; i--) x.insert(i, i + 0.5);
    for(int i = -10; i <= 100; i++) EXPECT_EQ(i, x.pop().first);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}