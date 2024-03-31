#include <iostream>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

TreeNode *Invert(TreeNode *tree)
{
    if (!tree)
        return NULL;
    TreeNode *res = tree;
    TreeNode *temp_left = tree->left;
    TreeNode *left = Invert(tree->right);
    TreeNode *right = Invert(temp_left);
    return res;
}

int main()
{
    TreeNode *node1 = new TreeNode(11);
    TreeNode *node2 = new TreeNode(5);
    node1->left = node2;
    TreeNode *node3 = new TreeNode(15);
    node1->right = node3;
    TreeNode *node4 = new TreeNode(2);
    node2->left = node4;
    TreeNode *node5 = new TreeNode(9);
    node2->right = node5;
    TreeNode *node6 = new TreeNode(23);
    node3->right = node6;

    TreeNode *inverted = Invert(node1);
}