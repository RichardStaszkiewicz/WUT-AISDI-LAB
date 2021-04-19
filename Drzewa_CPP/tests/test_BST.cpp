#include <gtest/gtest.h>
#include "BST.hpp"

BST_node *tree1()
{
    BST_node *root = new BST_node(56);
    root->add_value(32);
    root->add_value(45);
    root->add_value(86);
    root->add_value(73);
    root->add_value(11);
    root->add_value(67);
    root->add_value(5);
    root->add_value(55);
    root->add_value(78);
    root->add_value(98);
    root->add_value(76);
    root->add_value(99);
    return root;
}

BST_node *tree2()
{
    BST_node *root = new BST_node(-12);
    for(int i = 0; i < 100; i++) root->add_value(i);
    for(int i = 0; i > -100; i--) root->add_value(i);
    return root;
}

BST_node *t1 = tree1();
BST_node *t2 = tree2();

TEST(bool_true, true_test)
{
    EXPECT_TRUE(true);
}

TEST(bool_false, false_test)
{
    EXPECT_FALSE(false);
}

int main(int argc, char **argv)
{
    t1->print_as_root(0);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}