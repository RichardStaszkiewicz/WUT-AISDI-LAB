#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "heap.hpp"


TEST(test_construct, default_init)
{
    heappy x;
    x.insert(-12);
    x.insert(-2);
    x.insert(4);
    EXPECT_EQ(x.pop(), -12);
    EXPECT_EQ(x.pop(), -2);
    EXPECT_EQ(x.pop(), 4);
}

TEST(test_construct, custom_init)
{
    heappy x(3);
    x.insert(-12);
    x.insert(-2);
    x.insert(4);
    EXPECT_EQ(x.pop(), -12);
    EXPECT_EQ(x.pop(), -2);
    EXPECT_EQ(x.pop(), 4);
}

TEST(test_construct, custom_init2)
{
    heappy x(20);
    for(int i = 100; i >= -10; i--) x.insert(i);
    for(int i = -10; i <= 100; i++) EXPECT_EQ(i, x.pop());
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}