#include "pch.h"
#include "TreeforFinal.h"
TEST(TreeCountInternalNodesHelperTest, BasicTest) 
{
    Tree<int>::Node node1(1, nullptr, nullptr);
    Tree<int>::Node node2(2, nullptr, nullptr);
    Tree<int>::Node node3(3, nullptr, nullptr);

    node1.left = make_shared<Tree<int>::Node>(node2);
    node1.right = make_shared<Tree<int>::Node>(node3);

    Tree<int> tree(make_shared<Tree<int>::Node>(node1));

    EXPECT_EQ(tree.countInternalNodes(), 1);

}
TEST(TreeCountNodesHelperTest, BasicTest) 
{
    Tree<int>::Node node1(1, nullptr, nullptr);
    Tree<int>::Node node2(2, nullptr, nullptr);
    Tree<int>::Node node3(3, nullptr, nullptr);

    node1.left = make_shared<Tree<int>::Node>(node2);
    node1.right = make_shared<Tree<int>::Node>(node3);

    Tree<int> tree(make_shared<Tree<int>::Node>(node1));

    EXPECT_EQ(tree.countNodes(), 3);

}
TEST(TreeExternalPathLengthHelperTest, BasicTest) 
{
    Tree<int>::Node node1(1, nullptr, nullptr);
    Tree<int>::Node node2(2, nullptr, nullptr);
    Tree<int>::Node node3(3, nullptr, nullptr);

    node1.left = make_shared<Tree<int>::Node>(node2);
    node1.right = make_shared<Tree<int>::Node>(node3);

    Tree<int> tree(make_shared<Tree<int>::Node>(node1));

    EXPECT_EQ(tree.externalPathLength(), 2);

}