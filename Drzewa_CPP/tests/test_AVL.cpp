#include <gtest/gtest.h>
#include "AVL.hpp"


// problem - obsługa duplikatów w BST
// ignorowanie duplikatóe w AVL


TreeNode *tree1()
{
    TreeNode *root = NULL;
    root = add_value(root, 10);
    root = add_value(root, 271);
    root = add_value(root, 2);
    root = add_value(root, 21);
    root = add_value(root, 18);
    return root;
}


TreeNode *tree2()
{
    TreeNode *root = NULL;
    for(int i = 0; i < 100; i++) root = add_value(root, i);
    return root;
}


TreeNode *t1 = tree1();
TreeNode *t2 = tree2();


TEST(test_creating, single_node)
{
    TreeNode *root = NULL;
    root = add_value(root, 5);
    EXPECT_EQ(root->step, 1);
    root = add_value(root, 7);
    EXPECT_EQ(root->right_son->value, 7);
    EXPECT_EQ(root->right_son->left_son, nullptr);
    EXPECT_EQ(root->right_son->right_son, nullptr);
    EXPECT_EQ(root->right_son->step, 1);
    EXPECT_EQ(root->step, 2);
}


TEST(test_creating, node_simple_aligment)
{
    TreeNode *root = NULL;
    root = add_value(root, 5);
    root = add_value(root, 7);
    EXPECT_EQ(root->right_son->value, 7);
    EXPECT_EQ(root->right_son->left_son, nullptr);
    EXPECT_EQ(root->right_son->right_son, nullptr);
    EXPECT_EQ(root->right_son->step, 1);
    EXPECT_EQ(root->step, 2);
    root = add_value(root, -9.12);
    EXPECT_EQ(root->left_son->value, -9.12);
    EXPECT_EQ(root->left_son->left_son, nullptr);
    EXPECT_EQ(root->left_son->right_son, nullptr);
    EXPECT_EQ(root->left_son->step, 1);
    EXPECT_EQ(root->step, 2);
    TreeNode *root2 = NULL;
    root2 = add_value(root2, -1);
    root2 = add_value(root2, -1);
    EXPECT_EQ(root2->step, 1);
    EXPECT_EQ(root2->left_son, nullptr);
    EXPECT_EQ(root2->right_son, nullptr);

}


TEST(test_rotation, left_rotation)
{
    TreeNode *root = NULL;
    root = add_value(root, 5);
    root = add_value(root, 7);
    root = add_value(root, 8);
    EXPECT_EQ(root->value, 7);
    EXPECT_FALSE(root->right_son == nullptr);
    EXPECT_FALSE(root->left_son == nullptr);
    EXPECT_EQ(root->step, 2);
    EXPECT_EQ(root->right_son->value, 8);
    EXPECT_EQ(root->right_son->left_son, nullptr);
    EXPECT_EQ(root->right_son->right_son, nullptr);
    EXPECT_EQ(root->right_son->step, 1);
    EXPECT_EQ(root->left_son->value, 5);
    EXPECT_EQ(root->left_son->left_son, nullptr);
    EXPECT_EQ(root->left_son->right_son, nullptr);
    EXPECT_EQ(root->left_son->step, 1);
}


TEST(test_rotation, right_rotation)
{
    TreeNode *root = NULL;
    root = add_value(root, 5);
    root = add_value(root, 4);
    root = add_value(root, 3);
    EXPECT_EQ(root->value, 4);
    EXPECT_FALSE(root->right_son == nullptr);
    EXPECT_FALSE(root->left_son == nullptr);
    EXPECT_EQ(root->step, 2);
    EXPECT_EQ(root->right_son->value, 5);
    EXPECT_EQ(root->right_son->left_son, nullptr);
    EXPECT_EQ(root->right_son->right_son, nullptr);
    EXPECT_EQ(root->right_son->step, 1);
    EXPECT_EQ(root->left_son->value, 3);
    EXPECT_EQ(root->left_son->left_son, nullptr);
    EXPECT_EQ(root->left_son->right_son, nullptr);
    EXPECT_EQ(root->left_son->step, 1);
}


TEST(test_rotation, lr_rotation)
{
    TreeNode *root = NULL;
    root = add_value(root, 10);
    root = add_value(root, 12);
    root = add_value(root, 11);
    EXPECT_EQ(root->value, 11);
    EXPECT_FALSE(root->right_son == nullptr);
    EXPECT_FALSE(root->left_son == nullptr);
    EXPECT_EQ(root->step, 2);
    EXPECT_EQ(root->right_son->value, 12);
    EXPECT_EQ(root->right_son->left_son, nullptr);
    EXPECT_EQ(root->right_son->right_son, nullptr);
    EXPECT_EQ(root->right_son->step, 1);
    EXPECT_EQ(root->left_son->value, 10);
    EXPECT_EQ(root->left_son->left_son, nullptr);
    EXPECT_EQ(root->left_son->right_son, nullptr);
    EXPECT_EQ(root->left_son->step, 1);
}


TEST(test_rotation, rl_rotation)
{
    TreeNode *root = NULL;
    root = add_value(root, 10);
    root = add_value(root, 8);
    root = add_value(root, 9);
    EXPECT_EQ(root->value, 9);
    EXPECT_FALSE(root->right_son == nullptr);
    EXPECT_FALSE(root->left_son == nullptr);
    EXPECT_EQ(root->step, 2);
    EXPECT_EQ(root->right_son->value, 10);
    EXPECT_EQ(root->right_son->left_son, nullptr);
    EXPECT_EQ(root->right_son->right_son, nullptr);
    EXPECT_EQ(root->right_son->step, 1);
    EXPECT_EQ(root->left_son->value, 8);
    EXPECT_EQ(root->left_son->left_son, nullptr);
    EXPECT_EQ(root->left_son->right_son, nullptr);
    EXPECT_EQ(root->left_son->step, 1);
}


TEST(test_find, find)
{
    EXPECT_TRUE(find(t1, 21));
    EXPECT_FALSE(find(t2, 12.21));
    TreeNode *root = NULL;
    root = add_value(root, 1.111);
    EXPECT_FALSE(find(root, 1));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}