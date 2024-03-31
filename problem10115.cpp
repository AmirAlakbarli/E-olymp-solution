#include <iostream>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

bool compare(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    if (left->val == right->val)
        return compare(left->left, right->right) && compare(left->right, right->left);
    return false;
}

bool isSymmetric(TreeNode *tree)
{
    return compare(tree->left, tree->right);
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

    cout << (isSymmetric(node1) ? "true" : "false");
}