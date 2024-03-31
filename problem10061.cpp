#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *Minimum(TreeNode *tree)
{
    if (tree->left == NULL)
        return tree;
    else
        return Minimum(tree->left);
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

    TreeNode *minNode = Minimum(node1);
    cout << minNode->val;
}