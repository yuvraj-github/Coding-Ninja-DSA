void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    BinaryTreeNode<int> *left = root->left;
    root->left = root->right;
    root->right = left;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}