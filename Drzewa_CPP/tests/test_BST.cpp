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

TEST(test_creating, node_constructor)
{
    BST_node node{12};
    EXPECT_EQ(12, node.node_value);
    EXPECT_TRUE(nullptr == node.parent);
    EXPECT_TRUE(nullptr == node.son_right);
    EXPECT_TRUE(nullptr == node.son_left);
}

TEST(test_creating, add_node)
{
    BST_node root{12};
    root.add_value(19);
    EXPECT_EQ(19, root.son_right->node_value);
    EXPECT_TRUE(&root == root.son_right->parent);
    EXPECT_TRUE(nullptr == root.son_right->son_right);
    EXPECT_TRUE(nullptr == root.son_right->son_left);
    root.add_value(-11);
    EXPECT_EQ(-11, root.son_left->node_value);
    EXPECT_TRUE(&root == root.son_left->parent);
    EXPECT_TRUE(nullptr == root.son_left->son_right);
    EXPECT_TRUE(nullptr == root.son_left->son_left);
    BST_node root2{10};
    root2.add_value(10);
    EXPECT_EQ(10, root2.son_left->node_value);
    EXPECT_TRUE(&root2 == root2.son_left->parent);
    EXPECT_TRUE(nullptr == root2.son_left->son_right);
    EXPECT_TRUE(nullptr == root2.son_left->son_left);
}


TEST(test_operations, find)
{
    EXPECT_TRUE(t1->find_value(76));
    EXPECT_TRUE(t1->find_value(98));
    EXPECT_FALSE(t1->find_value(-111));
    EXPECT_TRUE(t2->find_value(-10));
    EXPECT_TRUE(t2->find_value(98));
    EXPECT_FALSE(t2->find_value(-111));
}

TEST(test_operations, delete_value)
{
    // to be impemented
    EXPECT_FALSE(false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}